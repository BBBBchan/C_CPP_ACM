#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <Windows.h>
#include <cstdio>
#include <string>
using namespace std;

#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")

MYSQL mysql; //mysql连接
MYSQL_FIELD* fd;  //字段列数组
char field[32][32];  //存字段名二维数组
MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
char query[150]; //查询语句


class bus {
private:
	char bus_num[10] = ""; //车牌号
	int type = 0;			//车辆类型
	int max_size = 0;		//承载人数
	string driver_name = "";//司机姓名
	int start_time = 0;		//开始运行时间
	int end_time = 0;		//结束运行时间
	int arrive_time = 0;	//预计到站时间
	int leave_time = 0;		//预计离站时间
	int act_arrive_time = 0;//实际到站时间
	int act_leave_time = 0;//实际离站时间
	int now_size = 0;		//当前车上人数
	float accuracy;			//准时率
	int total_time;			//总运行次数
	int accurate_time;		//准点运行次数
public:
	char* get_bus_num(){ return bus_num; }//获取车牌号
	void set_bus_num(char* num) { //设置车牌号
		strcpy_s(bus_num, num);
	}
	void add_total_time() { total_time++; }//总次数自增
	void add_accurate_time() { accurate_time++; }//准时次数自增
	void add_now_size() { now_size++; }//当前车上人数自增
	void set_bus_act_arrive_time(int time) { act_arrive_time = time; }//设置实际到站时间
	int get_act_arrive_time() { return act_arrive_time; }//获取实际到站时间
	int get_arrive_time() { return arrive_time; }//获取预计到站时间
	int get_total_time() { return total_time; }//获取总运行次数
	int get_accurate_time() { return accurate_time; }//获取准时运行次数
	int get_max_size() { return max_size; }//获取承载人数
	void print_time(int time) {
		int hour = time / 60;
		int minute = time % 60;
		printf("%02d:%02d", hour, minute);
	}//打印时间
	void show_info() {							//展示车辆信息
		cout << "以下是当前车辆信息: " << endl;
		cout << "车牌号: " << bus_num << endl;
		cout << "汽车类型: " << type << endl;
		cout << "最大容量: " << max_size << endl;
		cout << "当前人数: " << now_size << endl;
		cout << "运行时段: ";
		print_time(start_time);
		cout << " ~ ";
		print_time(end_time);
		cout << endl;
		cout << "预计到站与离开时间: ";
		print_time(arrive_time);
		cout << " ~ ";
		print_time(leave_time);
		cout << endl;
		cout << "实际到站与离开时间: ";
		print_time(act_arrive_time);
		cout << " ~ ";
		print_time(act_leave_time);
		cout << endl;
		cout << "总计运行次数: " << total_time << endl;
		cout << "准时运行次数: " << accurate_time << endl;
		cout << "准时率: " << accuracy << endl;
	}
	void get_info(MYSQL_ROW info);//解析数据库获取的信息并写入对象
	int get_now_size() { return now_size; }//获取当前车上人数
	float get_accuracy() { accuracy = (float)accurate_time / (float)total_time; return accuracy; }//求解并写入准时率
};


class card {
private:
	char name[20] = ""; //持卡人姓名
	int type = 0;		//一卡通类型
	int now_number = 0;//当月乘车次数
	int balance = 0;	//卡内余额
	char workplace[30]; //工作地点
	int validity_period = 0; //有效期
public:
	int card_id = 0;	//一卡通ID
	int get_now_number() { return now_number; }//获取当月乘车次数
	int get_balance() { return balance; }//获取余额
	int get_type() { return type; }//获取一卡通类型
	char* get_name() { return name; }//获取持卡人姓名
	char* get_workplace() { return workplace; }//获取工作地点
	void get_info(MYSQL_ROW info);//解析数据库获取的信息并写入对象
	void show_info();				//展示一卡通基本信息
	bool use_card(bus& now_bus);    //当前持卡人上车刷卡
	void fill_card(char *name_in, int type_in, int balance_in, char* workplace_in, int card_id_in) {//建立新卡时，根据用户传入信息填充当前对象的初始成员信息并写入数据库。
		strcpy_s(name, name_in);
		type = type_in;
		balance = balance_in;
		strcpy_s(workplace, workplace_in);
		card_id = card_id_in;
		validity_period = 30;
	}
};

bool ConnectDatabase()// 连接数据库
{
	//初始化mysql
	mysql_init(&mysql);  //连接mysql，数据库

	//返回false则连接失败，返回true则连接成功
	if (!(mysql_real_connect(&mysql, "localhost", "root", "123456", "cpp", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Connected...\n");
		return true;
	}
}

bool QueryDatabase(card &now_card)// 根据传入card类型对象的card_id在数据库内查询数据记录并使用get_info方法写入该对象，返回是否操作成功。
{
	mysql_query(&mysql, "set names gbk");
	sprintf_s(query, "select * from cards where card_id = %d", now_card.card_id);
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	res = mysql_store_result(&mysql);
	//打印数据行数
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名
		strcpy_s(field[i], fd->name);		//写入字段名
	int j = mysql_num_fields(res);  // 获取列数
	while (column = mysql_fetch_row(res))
	{
		now_card.get_info(column);	//为当前对象填充内容
		return true;
	}
	return false;
}

bool QueryDatabase_bus(bus& now_bus){// 根据传入bus类型对象now_bus的车牌号信息在数据库中检索信息，返回操作是否成功
	mysql_query(&mysql, "set names gbk");
	sprintf_s(query, "select * from bus where bus_num = '%s'", now_bus.get_bus_num());
	//返回0 查询成功，返回1查询失败
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	res = mysql_store_result(&mysql);
	//打印数据行数
	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名
		strcpy_s(field[i], fd->name);
	int j = mysql_num_fields(res);  // 获取列数
	while (column = mysql_fetch_row(res))
	{
		cout << endl;
		now_bus.get_info(column);
		return true;
	}
	return false;
}

bool new_card(card a){//根据传入的card类型对象在数据库内添加对应一卡通记录，实现注册一卡通功能，返回操作是否成功。
	mysql_query(&mysql, "set names gbk");
	sprintf_s(query, "insert into cards values (%d, %d, 0, '%s', %d, '%s', 30);", a.get_type(), a.get_balance(),a.get_name(), a.card_id, a.get_workplace());  //可以想办法实现手动在控制台手动输入指令
	cout << query << endl;
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		return true;
	}
}

bool ModifyData(card now_card)//根据传入的card类型对象在数据库内实现对当前一卡通数据的更新，返回操作是否成功
{
	sprintf_s(query, "update cards set balance=%d, now_num=%d where card_id=%d", now_card.get_balance(), now_card.get_now_number(), now_card.card_id);
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	return true;
}

bool ModifyData_bus(bus now_bus)// 根据传入bus类型对象now_bus修改数据库中的记录，返回操作是否成功。
{
	sprintf_s(query, "update bus set now_size = %d, act_arrive_time = %d, act_leave_time = %d where bus_num='%s'", now_bus.get_now_size(),  now_bus.get_act_arrive_time(), now_bus.get_act_arrive_time()+10,now_bus.get_bus_num());
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	sprintf_s(query, "update bus set accuracy = %f, total_time = %d, accurate_time = %d where bus_num = '%s'", now_bus.get_accuracy(), now_bus.get_total_time(), now_bus.get_accurate_time(),now_bus.get_bus_num());
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	return true;
}

bool delete_card(card a){	 // 根据传入card类型对象在数据库内删除对应一卡通信息，实现注销一卡通功能，返回操作是否成功。
	mysql_query(&mysql, "set names gbk");
	char query[100];
	sprintf_s(query, "delete from cards where card_id= %d", a.card_id);
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		return true;
	}
}

void card::get_info(MYSQL_ROW info) {
	type = info[0][0]-'0';
	balance = now_number = validity_period = 0;
	for (int i = 0; i < strlen(info[1]); i++) {
		balance += (info[1][i] - '0');
		balance *= 10;
	}
	balance /= 10;
	for (int i = 0; i < strlen(info[2]); i++) {
		now_number += (info[2][i] - '0');
		now_number *= 10;
	}
	now_number /= 10;
	//name = info[3];
	strcpy_s(name, info[3]);
	//workplace = info[5];
	strcpy_s(workplace, info[5]);
	for (int i = 0; i < strlen(info[6]); i++) {
		validity_period += (info[6][i] - '0');
		validity_period *= 10;
	}
	validity_period /= 10;

}

void card::show_info() {
	cout << endl << "持卡人信息: " << endl;
	cout << "一卡通类型: " ;
	if (type == 1)
		cout << "教师卡" << endl;
	else if (type == 2)
		cout << "学生卡" << endl;
	else if (type == 3)
		cout << "限制卡" << endl;
	cout << "持卡人姓名: " << name << endl;
	cout << "一卡通编号: " << card_id << endl;
	cout << "所属单位: " << workplace << endl;
	cout << "卡内余额: " << balance << endl;
	cout << "有效期: " << validity_period << endl;
	cout << "当月已乘车次数: " << now_number << endl << endl;;
	if (balance < 5)
		cout << "您的余额较低，请注意充值" << endl;
}

bool card::use_card(bus &now_bus) {
	if (now_bus.get_now_size() >= now_bus.get_max_size()) {
		cout << "该辆班车已满，请乘坐下一辆" << endl << endl;
		return false;
	}
	else {
		now_bus.add_now_size();
	}
	if (type == 1) {
		cout << "刷卡成功！扣费0元" << endl;
		now_number++;
		return true;
	}
	else if (type == 2) {
		if (balance < 2) {
			cout << "余额不足！请充值后使用" << endl;
			return false;
		}
		else {
			balance -= 2;
			cout << "刷卡成功！扣费2元" << endl;
			now_number++;
			return true;
		}
	}
	else if (type == 3) {
		if (now_number < 20) {
			cout << "刷卡成功！扣费0元，本月剩余免费次数: " << 20 - now_number - 1 << "次" << endl;
			now_number++;
			if (now_number == 20)
				cout << "注意：这是您本月最后一次免费乘车，下次乘车开始将开始计费" << endl;
			return true;
		}
		else {
			if (balance < 2) {
				cout << "余额不足！请充值后使用" << endl;
				return false;
			}
			else {
				balance -= 2;
				cout << "刷卡成功！扣费2元，本月剩余免费次数: 0次" << endl;
				now_number++;
				return true;
			}
		}
	}
	return false;
}

void bus::get_info(MYSQL_ROW info) {
	type = info[0][0] - '0';
	driver_name = info[1];
	max_size = start_time = end_time = act_arrive_time = act_leave_time = leave_time = arrive_time =  0;
	for (int i = 0; i < strlen(info[2]); i++) {
		max_size += (info[2][i] - '0');
		max_size *= 10;
	}
	max_size /= 10;

	for (int i = 0; i < strlen(info[3]); i++) {
		start_time += (info[3][i] - '0');
		start_time *= 10;
	}
	start_time /= 10;
	
	for (int i = 0; i < strlen(info[4]); i++) {
		end_time += (info[4][i] - '0');
		end_time *= 10;
	}
	end_time /= 10;

	for (int i = 0; i < strlen(info[5]); i++) {
		arrive_time += (info[5][i] - '0');
		arrive_time *= 10;
	}
	arrive_time /= 10;

	for (int i = 0; i < strlen(info[6]); i++) {
		leave_time += (info[6][i] - '0');
		leave_time *= 10;
	}
	leave_time /= 10;
	
	act_arrive_time = 0;
	for (int i = 0; i < strlen(info[7]); i++) {
		act_arrive_time += (info[7][i] - '0');
		act_arrive_time *= 10;
	}
	act_arrive_time /= 10;

	act_leave_time = 0;
	for (int i = 0; i < strlen(info[8]); i++) {
		act_leave_time += (info[8][i] - '0');
		act_leave_time *= 10;
	}
	act_leave_time /= 10;
	now_size = 0;
	for (int i = 0; i < strlen(info[9]); i++) {
		now_size += (info[9][i] - '0');
		now_size *= 10;
	}
	now_size /= 10;
	strcpy_s(bus_num, info[10]);
	total_time = 0;
	for (int i = 0; i < strlen(info[12]); i++) {
		total_time += (info[12][i] - '0');
		total_time *= 10;
	}
	total_time /= 10;
	accurate_time = 0;
	for (int i = 0; i < strlen(info[13]); i++) {
		accurate_time += (info[13][i] - '0');
		accurate_time *= 10;
	}
	accurate_time /= 10;
}

int merge_time(string time_s) {// 针对输入的小时：分钟形式的字符串进行处理，转换成int类型并返回。
	int time_r = 0;
	time_r += 60 * ((time_s[0] - '0') * 10 + (time_s[1] - '0')) + (time_s[3] - '0') * 10 + (time_s[4] - '0');
	return time_r;
}

int main()
{
	ConnectDatabase();
	while (true) {
		cout << "欢迎使用一卡通系统，乘车过程请输入1， 乘车卡管理请输入0" << endl;
		int kase;
		cin >> kase;
		if (kase == 0) {
			card a;
			cout << "欢迎使用乘车卡管理系统， 办卡请输入1， 注销卡请输入2" << endl;
			int kase2;
			cin >> kase2;
			if (kase2 == 1) {
				int type, card_id, balance;
				char name[20], workplace[30];
				cout << "请依次输入持卡人姓名， 卡片类型编号， 初始金额， 工作地点， 一卡通编号" << endl;
				cin >> name >> type >> balance >> workplace >> card_id;
				a.fill_card(name, type, balance, workplace, card_id);
				a.show_info();
				if (new_card(a)) {
					cout << "办卡成功！" << endl;
				}
				else {
					cout << "办卡失败!" << endl;
				}
			}
			else if (kase2 == 2) {
				cout << "请输入要注销的一卡通ID" << endl;
				cin >> a.card_id;
				if (delete_card(a)) {
					cout << "注销成功！" << endl;
				}
				else
					cout << "注销失败!" << endl;
			}
		}
		else if (kase == 1) {
			cout << "请输入当前到达车辆的车牌号和到达时间" << endl;
			bus b;
			char num[10];
			cin >> num;// 车牌号
			string arrive_time;
			cin >> arrive_time;//实际到达时间
			b.set_bus_num(num);
			if (QueryDatabase_bus(b)) {//在数据库中查询b的车牌号
				b.set_bus_act_arrive_time(merge_time(arrive_time));//设置实际到站时间
				b.add_total_time();//总运行次数递增
				if (b.get_act_arrive_time() == b.get_arrive_time()) {//判断是否准点
					b.add_accurate_time();//准点次数自增
				}
				b.get_accuracy();//计算准点率
				ModifyData_bus(b);//修改数据库记录
				QueryDatabase_bus(b);//重新查询信息
				b.show_info();//展示信息
			}
			else {
				cout << "车牌号不存在，请重新输入！" << endl;
				continue;
			}

			cout << endl;
			card a;
			int temp_id;
			while (true) {	//卡号
				cout << "欢迎乘坐 " << b.get_bus_num() << " ,当前车辆的剩余座位为: " << b.get_max_size() - b.get_now_size() << " 请输入您的卡号，所有乘客刷卡或车辆人数已满后请输入0" << endl;
				cin >> temp_id;//输入一卡通ID
				if (temp_id == 0) {//上车结束
					break;
				}
				else {
					a.card_id = temp_id;//设置a的一卡通ID
				}

				if (QueryDatabase(a)) {//在数据库中查询a的一卡通ID
					if (a.use_card(b)) {//尝试刷卡上车
						ModifyData(a);//修改数据库记录
						a.show_info();//展示持卡人信息
						ModifyData_bus(b);//修改车辆数据库记录
					}
				}
				else {
					cout << "ID不存在，请重新输入ID" << endl;
				}
			}
			cout << "本次班车的到客率为: " << (float)((float)b.get_now_size() / (float)b.get_max_size()) << endl;
			cout << endl;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}
	}
	return 0;
}
