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
	char bus_num[10] = "";
	int type = 0;
	int max_size = 0;
	string driver_name = "";
	int start_time = 0;
	int end_time = 0;
	int arrive_time = 0;
	int leave_time = 0;
	int act_arrive_time = 0;
	int act_leave_time = 0;
	int now_size = 0;
	float accuracy;
	int total_time;
	int accurate_time;
public:
	char* get_bus_num(){ return bus_num; }
	void set_bus_num(char* num) { 
		strcpy_s(bus_num, num);
	}
	void add_total_time() { total_time++; }
	void add_accurate_time() { accurate_time++; }
	void add_now_size() { now_size++; }
	void set_bus_act_arrive_time(int time) { act_arrive_time = time; }
	int get_act_arrive_time() { return act_arrive_time; }
	int get_arrive_time() { return arrive_time; }
	int get_total_time() { return total_time; }
	int get_accurate_time() { return accurate_time; }
	int get_max_size() { return max_size; }
	void print_time(int time) {
		int hour = time / 60;
		int minute = time % 60;
		printf("%02d:%02d", hour, minute);
	}
	void show_info() {
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
	void get_info(MYSQL_ROW info);
	int get_now_size() { return now_size; }
	float get_accuracy() { accuracy = (float)accurate_time / (float)total_time; return accuracy; }
};


class card {
private:
	string name;
	int type = 0;
	int now_number = 0;
	int balance = 0;
	string workplace;
	int validity_period = 0;
public:
	int card_id = 0;
	int get_now_number() { return now_number; }
	int get_balance() { return balance; }
	void get_info(MYSQL_ROW info);
	void show_info();
	bool use_card(bus& now_bus);
};

bool ConnectDatabase()
{
	//初始化mysql
	mysql_init(&mysql);  //连接mysql，数据库

	//返回false则连接失败，返回true则连接成功
	if (!(mysql_real_connect(&mysql, "localhost", "root", "123456", "cpp", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
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

bool QueryDatabase(card &now_card)
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
		strcpy_s(field[i], fd->name);
	int j = mysql_num_fields(res);  // 获取列数
	while (column = mysql_fetch_row(res))
	{
		now_card.get_info(column);
		return true;
	}
	return false;
}

bool QueryDatabase_bus(bus& now_bus)
{
	mysql_query(&mysql, "set names gbk");
	sprintf_s(query, "select * from bus where bus_num = '%s'", now_bus.get_bus_num());
	cout << query << endl;
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

bool InsertData()
{
	sprintf_s(query, "insert into user values (%d, '%s');", 2, "BB");  //可以想办法实现手动在控制台手动输入指令
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
		return true;
	}
}
bool ModifyData(card now_card)
{
	sprintf_s(query, "update cards set balance=%d, now_num=%d where card_id=%d", now_card.get_balance(), now_card.get_now_number(), now_card.card_id);
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	return true;
}
bool ModifyData_bus(bus now_bus)
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
bool DeleteData()
{
	/*sprintf(query, "delete from user where id=6");*/
	char query[100];
	printf("please input the sql:\n");
	gets_s(query);  //这里手动输入sql语句
	if (mysql_query(&mysql, query))        //执行SQL语句
	{
		printf("Query failed (%s)\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		printf("Insert success\n");
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
	name = info[3];
	workplace = info[5];
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

int merge_time(string time_s) {
	int time_r = 0;
	time_r += 60 * ((time_s[0] - '0') * 10 + (time_s[1] - '0')) + (time_s[3] - '0') * 10 + (time_s[4] - '0');
	return time_r;
}
int main()
{
	ConnectDatabase();
	while (true) {
		cout << "欢迎使用一卡通系统，请输入当前到达车辆的车牌号和到达时间" << endl;
		bus b;
		char num[10];
		cin >> num;// 车牌号
		string arrive_time;
		cin >> arrive_time;
		b.set_bus_num(num);
		if (QueryDatabase_bus(b)) {
			b.set_bus_act_arrive_time(merge_time(arrive_time));
			b.add_total_time();
			if (b.get_act_arrive_time() == b.get_arrive_time()) {
				b.add_accurate_time();
			}
			b.get_accuracy();
			ModifyData_bus(b);
			QueryDatabase_bus(b);
			b.show_info();
		}
		else {
			cout << "车牌号不存在，请重新输入！" << endl;
			continue;
		}

		cout << endl;
		card a;
		int temp_id;
		while (true) {	//卡号
			cout << "欢迎乘坐 " << b.get_bus_num() << " ,当前车辆的剩余座位为: "<<b.get_max_size()-b.get_now_size()<<" 请输入您的卡号，所有乘客刷卡后请输入0" << endl;
			cin >> temp_id;
			if (temp_id == 0) {
				break;
			}
			else {
				a.card_id = temp_id;
			}
			if (QueryDatabase(a)) {
				if (a.use_card(b)) {
					ModifyData(a);
					a.show_info();
					ModifyData_bus(b);
				}
			}
			else {
				cout << "ID不存在，请重新输入ID" << endl;
			}
		}
		cout << "本次班车的到客率为: " << (float)((float)b.get_now_size() / (float)b.get_max_size()) << endl;
	}


}
