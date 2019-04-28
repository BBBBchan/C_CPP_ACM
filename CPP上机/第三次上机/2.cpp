#include <iostream>
using namespace std;
void print(int i){
	cout << i << endl;
}
void print(double i){
	cout << i << endl;
}
void print(char i){
	cout << i << endl;
}
int main(int argc, char const *argv[])
{
	int x = 1;
	double y = 1.1;
	char z = 'x';
	print(x);
	print(y);
	print(z);
	return 0;
}