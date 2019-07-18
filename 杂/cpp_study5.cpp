#include <iostream>
using namespace std;
class A
{
	int data;
public:
	A(int i){data = i;}
	A(){}
	void m();
	void n();
	~A(){cout <<"hello" <<endl;}
};
class B : public A{
public:
	B(){};
	~B(){cout << "bye" <<endl;};褚华
	
};
int main(int argc, char const *argv[])
{
	A *p[3];
	p[0] = new A;
	p[1] = new B;
	delete p[0];
	cout <<endl;
	delete p[1];
	cout <<endl; 
	return 0;
}