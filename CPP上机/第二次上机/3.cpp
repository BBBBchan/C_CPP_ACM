#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

string itoa(int i, char b[]){
	int temp = i,count=0;
	while(temp!=0){
		b[count] = temp%10 + '0';
		temp/=10;
		count++;
	}
	b[count] = '\0';
	char ans[10000];
	for(int j = strlen(b)-1; j >= 0; j--){
		ans[strlen(b)-1-j] = b[j];
	}
	ans[strlen(b)] = '\0';
	return ans;
}
int main(){
	int i;
	char b[10000];
	scanf("%d", &i);
	string ans = itoa(i,b);
	cout<<ans<<endl;
	return 0;
}