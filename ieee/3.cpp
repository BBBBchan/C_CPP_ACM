#include <cstdio>
#include <algorithm>
using namespace std;
long long cnt = 0;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--){
		cnt = 0;
		long long l, h, start, d1, d2;
		scanf("%lld %lld %lld %lld %lld", &l, &h, &start, &d1, &d2);
		long long a1,b1, a2, b2,ans, kase = 0;
		a1 = (d1-start)/l;
		b1 = (d1-start)%l;
		a2 = (d2-start)/l;
		b2 = (d2-start)%l;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < l; j++){
				if(min(a1,a2)<=i && max(a2,a1)>=i
					&& min(b2,b1)<=j && max(b2,b1)>=j){
					continue;
				}
				if(kase == 0){
					kase = 1;
					ans = i*l+j+start;
				}
				else
					ans ^= i*l+j+start;
				cnt++;
			}
		}
		printf("%lld\n", ans);
}
	return 0;
}