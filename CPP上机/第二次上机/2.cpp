#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
char a[10000];
int b[10000],x[10000];
int atoi(const char* a){
	int a_len = strlen(a), ans = 0;
	for(int i = 0; i<a_len; i++){
		ans+=a[i]-'0';
		ans*=10;
	}
	ans/=10;
	return ans;
}
int main(int argc, char const *argv[])
{
	scanf("%s", a);
	int ans = atoi(a);
	int temp1 = ans, temp2 = ans,count1=0,count2=0;
	cout << ans << endl;
	while(temp1 != 0){
		b[count1] = temp1%8;
		temp1/=8;
		count1++;
	}
	for(int i = count1-1; i >=0; i--){
		cout<<b[i];
	}
	cout<<endl;
	while(temp2 != 0){
		x[count2] = temp2%16;
		temp2/=16;
		count2++;
	}
	for(int i = count2-1; i >=0; i--){
		if(x[i] < 10)
			cout << x[i];
		else
			cout << char(x[i]-10+'A');
	}
	cout <<endl;
	return 0;
}