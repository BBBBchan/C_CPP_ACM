#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
double a[30];
char s[1000005];
int main(int argc, char const *argv[])
{
	double half;
	scanf("%lf", &half);
	for(int i = 0; i < 26; i++){
		char temp1;
		cin >> temp1;
		double temp2;
		scanf("%lf",&temp2);
		a[temp1-'A'] = temp2;
	}
	int now_l = 0;
	while(scanf("%c", &s[now_l]) != EOF){
		if((s[now_l] > 'Z' || s[now_l] < 'A') && (s[now_l] > 'z' || s[now_l] < 'a'))
			continue;
		else if(s[now_l] <= 'z' && s[now_l] >= 'a'){
			s[now_l] = s[now_l] -('a'-'A');
		}
		now_l++;
	}
	double ans = 0;
	for(int i = 1; i < now_l; i++){
	//	ans += sqrt(2*half*half*(1-cos((a[s[i]-'A'] - a[s[i-1]-'A'])*M_PI/180)));
		ans += fabs(2*half*sin((a[s[i]-'A']- a[s[i-1]-'A'])*M_PI/360.0));
	}
	ans += half;
	ans += 0.5;
	printf("%.0lf\n", ans);

	return 0;
}