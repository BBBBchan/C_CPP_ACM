#include <iostream>
using namespace std;
class instrument
{
public:
	virtual void play(){cout<<"play instrument"<<endl;}
	
};

class piano : public instrument{
public:
	void play() {cout << "play piiano"<<endl;}
};
int main(){
	instrument a;
	a.play();
	instrument *p[2];
	p[0] = new piano;
	p[1] = new instrument;
	p[0]->play();
	p[1]->play();
	piano b;
	b.play();

	instrument temp;
	piano temp2;
	temp.play();
	temp2.play();
	temp = temp2;
	temp.play();
	// int x;
	// cin >> x;
	// const int size = x;
	// double array[size];
	// cout << sizeof(array)/sizeof(double) <<endl;
	// int m = 123;
	// int n = 64;
	// int * const p = &m;
	// const int * q = &m;
	// *p = 12;
	// q = &n; 
	// cout << *p <<endl;
	// cout << *q <<endl;
	return 0;
}