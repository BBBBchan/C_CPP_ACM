#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
long long int c[maxn][maxn],a[maxn][2];
int main(int argc, char const *argv[])
{
	int n;
	long long int s;
	scanf("%d %lld",&n,&s);
	s*=2;
	long long int ss = -1*s;
	for(int i = 0; i < n; i++){
		scanf("%lld %lld", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
        c[i][j] = a[i][0] * a[j][1] -a[j][0] * a[i][1];
        }
    }
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			register long long cp = c[i][j];
			for(int k = j+1; k < n; k++){
				long long int temp = cp+c[j][k]-c[i][k];
				if(temp == s || temp == ss){
					puts("Yes");
                    printf("%lld %lld\n", a[i][0], a[i][1]);
                    printf("%lld %lld\n", a[j][0], a[j][1]);
                    printf("%lld %lld\n", a[k][0], a[k][1]);
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}