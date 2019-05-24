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
	bool use_card();
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
	cout << "当月已乘车次数: " << now_number << endl;
	if (balance < 5)
		cout << "您的余额较低，请注意充值" << endl;
}

bool card::use_card() {
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

int main()
{
	ConnectDatabase();
	cout << "欢迎使用一卡通系统，请输入您的ID" << endl;
	while (true) {
		card a;
		int temp_id;
		cin >> temp_id;
		a.card_id = temp_id;
		if (QueryDatabase(a)) {
			if (a.use_card()) {
				ModifyData(a);
				a.show_info();
			}
		}
		else {
			cout << "ID不存在，请重新输入ID" << endl;
		}
	}
}
