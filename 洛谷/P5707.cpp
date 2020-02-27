#include <cstdio>
int main(int argc, char const *argv[])
{
	int s, v, time;
	scanf("%d %d", &s, &v);
	if(s%v == 0){
		time = s/v +10;
	}
	else
		time = s/v+11;
	int hour = time/60;
	int minute = time%60;
	int ansmin = 0-minute+60;
	int anshour = 7 - hour;
	if(anshour < 0){
		anshour+=24;
	}
	printf("%02d:%02d", anshour, ansmin);
	return 0;
}