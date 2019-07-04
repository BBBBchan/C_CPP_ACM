#include <string>
#include <iostream>
using namespace std;
class Historgram
{
private:
	int a,b,c;
public:
	Historgram(int x,int y = 8,int z =3)
	{
		a = x;
		b = y;
		c = z;
		if(a < z || a > y)
			cout << "Error" << endl;
	}
	int volume();
};
int Historgram::volume()
{
	cout <<  a;
}
int main()
{
	Historgram B1(2,9,1);
	B1.volume();
}