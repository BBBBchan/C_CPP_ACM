#include <iostream>
#include <string>
class test{
private:
	std::string company_name;
	int salary_max;
	int salary_min;
	int difference;
	void set_difference(){
		difference = salary_max - salary_min;
	}
public:
	test(const std::string name, int value1, int value2);
	void get_company_name(const std::string name){
		company_name = name;
	}
	int get_max(int value);
	int get_min(int value);
	void showdata();
};

test::test(const std::string name, int value1, int value2){
	salary_max = value1;
	salary_min = value2;
	company_name = name;
	set_difference();
}

int test::get_max(int value){
	salary_max = value;
	set_difference();
}

int test::get_min(int value){
	salary_min = value;
	set_difference();
}
void test::showdata(){
	std::cout << company_name << std::endl;
	std::cout << salary_max << std::endl;
	std::cout << salary_min << std::endl;
	std::cout << difference << std::endl;
}

int main(int argc, char const *argv[])
{
	test a = test("qwq", 10000, 1);
	a.showdata();
	a.get_company_name("qaq");
	int temp1 = a.get_max(1234);
	int temp2 = a.get_min(12);
	a.showdata();
	return 0;
}