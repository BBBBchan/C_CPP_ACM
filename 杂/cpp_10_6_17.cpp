#include <iostream>
#include <string>
using namespace std;

class test1{
private:
	static int a;
	static int b;
public:
	test1();
	void set_B();
	int takea(){
		return a;
	}
	void show(){
		cout << "a = " << a<<endl;
		cout << "b = " << b<<endl;
	}
};
int test1::a;
int test1::b;

class test2{
private:
	static int c;
	static int d;
public:
	test2();
	void set_D();
	int takec(){
		return c;
	}
	void show(){
		cout<< "c = " << c <<endl;
		cout << "d = " << d<<endl;
	}
};
int test2::c;
int test2::d;

test1::test1(){
	a = 1;
}


test2::test2(){
	c = 3;
}

void test1::set_B(){
	test2 temp;
	b = temp.takec();
}
void test2::set_D(){
	test1 temp;
	d = temp.takea();
}

int main(int argc, char const *argv[])
{
	test1 x;
	test2 y;
	x.set_B();
	y.set_D();
	x.show();
	y.show();
	return 0;
}