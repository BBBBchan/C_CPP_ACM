#include <iostream>
using namespace std;
class A{
public:
	static int a;
    static int set_aa();

};
int A::a = 1;
class B{
public:
	static int bb;
	static int  set_bb( )
	{
		bb += A::a;
		return bb;
	}
};
int B::bb = 1;
int A::set_aa(){
	a += B::bb;
	return a;
}
// A A;
// B B;
// void B::set_bb(int x)
// {
// 	 bb = x + A.aa;
// 	 cout << bb <<" " << A.aa << endl;
// }

int main()
{

	// A.set_aa(1);
	// B.set_bb(2);
	A A1;
	B B1;
	cout << A1.set_aa()<<endl;
	cout << B1.set_bb()<<endl;
	cout << A1.set_aa()<<endl;
}