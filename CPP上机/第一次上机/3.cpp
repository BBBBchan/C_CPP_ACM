#include <iostream>
using namespace std;
struct date
{
	int year;
	int month;
	int day;
};
int main(int argc, char const *argv[])
{
	date D = {2019,4,14};
	printf("Initialized date is %04d/%02d/%02d\n", D.year, D.month, D.day);
	cin >> D.year;
	cin >> D.month;
	cin >> D.day;
	cout << "Modified date is " << D.year << '/' << D.month << '/' <<D.day;
	return 0;
}