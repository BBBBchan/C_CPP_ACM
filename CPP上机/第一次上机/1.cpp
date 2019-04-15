#include <iostream>
using namespace std;
struct month
{
	char name[10];
	int day;
};
int main(int argc, char const *argv[])
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char mon[12][10] = {"Januray", "Feburary", "March","April","May","June","July","August",
						"September","October","November","December"};
	for(int i = 0; i < 12; i++)
		cout << mon[i] << ' ' << days[i] << endl;

	cout << endl;
	
	month months[12] = {"Januray",31,"Feburary",28, "March", 31, "April", 30, "May", 31,
 						"June", 30, "July", 31, "August", 31, "September", 30, "October", 31,
 						"November", 30, "December", 31};
 	for(int i = 0 ; i < 12; i++)
		cout << months[i].name << ' ' <<months[i].day << endl; 
	return 0;
}		