#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct words{
	char word[35];
	int len;
}a[35];
bool cmp(words a, words b){
	return a.len < b.len;
}
int main(int argc, char const *argv[])
{
	int i = 0;
	while(scanf("%s", a[i].word) && a[i].word[0]!='#'){
		a[i].len = strlen(a[i].word);
		i++;
	}
	for(int m = 0; m < i; m++){
		for(int n = 1; n < i-m; n++){
			if(a[n-1].len > a[n].len){
				words temp = a[n-1];
				a[n-1] = a[n];
				a[n] = temp;
			}
		}
	}
	for(int j = 0; j < i; j++)
		printf("%s ", a[j].word);
	return 0;
}