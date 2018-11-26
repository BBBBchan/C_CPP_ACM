#include <cstdio>
#include <algorithm>
using namespace std;
struct string
{
	char s[50];
	int count;
	int mark;
}a[100];
int cmp(string a, string b){
	if(a.count!=b.count)
		return a.count < b.count;
	else
		return a.mark < b.mark;
}
int main(int argc, char const *argv[])
{
	int k = 0;
	scanf("%d", &k);
	while(k--){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
			a[i].count = 0;
		for(int i = 0; i < m; i++){
			a[i].mark = i;
			scanf("%s",a[i].s);
			for(int j = 0; j < n; j++){
				for(int k = j+1; k<n; k++){
					if(a[i].s[j] > a[i].s[k])
						a[i].count++;
				}
			}
		}
		sort(a,a+m,cmp);
		for(int i = 0; i < m; i++){
			printf("%s\n", a[i].s);
		}
		if(k!=0)
			printf("\n");
	}
	return 0;
}