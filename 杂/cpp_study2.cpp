#include <iostream>
using namespace std;

class A{
private:
	int i;
public:
	A(int temp);
	A(const A &test);
	A();
	void set(int i){this->i = i;}
	void f();
	~A();
};

A::A(int temp):
i(temp){
	cout << "here"<<endl;
}

A::A():
i(100){}

void A::f(){
	// cout << i<< endl;
//	this->i = 20;
	cout << i << endl;
}

A::A(const A &test){
	i = 30;
	cout <<"hereeeee"<<endl;
}

A::~A(){
	cout <<"bye"<<endl;
}

void print(A test2){
	test2.f();
}

A print2(){
	A test3;
	return test3;
}

int main(int argc, char const *argv[])
{
	{
	A a(20),b;
	A c = a;
	print(a);
	a.f();
	b.f();
	c.f();
	cout << endl;
	A d = a;
	d.f();
	}

	cout << endl;
	A *e = new A[10];
	e[0].set(10);
	e[0].f();
	return 0;
}