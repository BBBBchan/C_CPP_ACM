#include <cstdio>
#include <algorithm>
using namespace std;
struct string
{
	char s[50];
	int count;
}a[100];
int cmp(string a, string b){
	return a.count < b.count;
}
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		a[i].count = 0;
		scanf("%s",a[i].s);
		for(int j = 0; i < n; j++){
			for(int k = j+1; k<n; j++){
				if(a[i].s[j] > a[i].s[k])
					a[i].count++;
			}
		}
	}
	sort(a,a+m,cmp);
	for(int i = 0; i < m; i++){
		printf("%s\n", a[i].s);
	}
	return 0;
}