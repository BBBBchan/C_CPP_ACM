#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
int main(int argc, char const *argv[])
{
	int t;
	int date, year,month,day;
	char mon[15];
	scanf("%d", &t);
	printf("%d\n", t);
	while(t--){
		scanf("%d. %s %d", &date, mon, &year);
		if(strstr(mon,"pop"))
			month = 1;
		else if(strstr(mon,"no"))
			month = 2;
		else if(strstr(mon,"zip"))
			month = 3;
		else if(strstr(mon,"zotz"))
			month = 4;
		else if(strstr(mon,"tzec"))
			month = 5;
		else if(strstr(mon,"xul"))
			month = 6;
		else if(strstr(mon,"yoxkin"))
			month = 7;
		else if(strstr(mon,"mol"))
			month = 8;
		else if(strstr(mon,"chen"))
			month = 9;
		else if(strstr(mon,"yax"))
			month = 10;
		else if(strstr(mon,"zac"))
			month = 11;
		else if(strstr(mon,"ceh"))
			month = 12;
		else if(strstr(mon,"mac"))
			month = 13;
		else if(strstr(mon,"kankin"))
			month = 14;
		else if(strstr(mon,"muan"))
			month = 15;
		else if(strstr(mon,"pax"))
			month = 16;
		else if(strstr(mon,"koyab"))
			month = 17;
		else if(strstr(mon,"cumhu"))
			month = 18;
		else if(strstr(mon,"uayet"))
			month = 19;
	day = date+(month-1)*20+365*year;
	year = day/260;
	month = (day%260)%13+1;
	date = (day%260)%20+1;
	if(date == 1)
		printf("%d imix %d\n",month, year);
	else if(date == 2)
		printf("%d ik %d\n",month,year);
	else if(date == 3)
		printf("%d akbal %d\n",month,year);
	else if(date == 4)
		printf("%d kan %d\n",month,year);
	else if(date == 5)
		printf("%d chicchan %d\n",month,year);
	else if(date == 6)
		printf("%d cimi %d\n",month,year);
	else if(date == 7)
		printf("%d manik %d\n",month,year);
	else if(date == 8)
		printf("%d lamat %d\n",month,year);
	else if(date == 9)
		printf("%d muluk %d\n",month,year);
	else if(date == 10)
		printf("%d ok %d\n",month,year);
	else if(date == 11)
		printf("%d chuen %d\n",month,year);
	else if(date == 12)
		printf("%d eb %d\n",month,year);
	else if(date == 13)
		printf("%d ben %d\n",month,year);
	else if(date == 14)
		printf("%d ix %d\n",month,year);
	else if(date == 15)
		printf("%d mem %d\n",month,year);
	else if(date == 16)
		printf("%d cib %d\n",month,year);
	else if(date == 17)
		printf("%d caban %d\n",month,year);
	else if(date == 18)
		printf("%d eznab %d\n",month,year);
	else if(date == 19)
		printf("%d canac %d\n",month,year);
	else if(date == 20)
		printf("%d ahau %d\n",month,year);
	}
	return 0;
}