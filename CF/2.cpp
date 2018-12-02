#include <cstdio>
#include <cstring>
char a[10005];
int maxlen = 0, maxlen1 = 0, maxlen2 = 0;
int main(int argc, char const *argv[])
{
	int n,block = 0;
	scanf("%d", &n);
	scanf("%s",a);
	for(int i = 0; i < n; i++){
		int kase = 0, count=0;
		while(a[i] == 'G' && i < n){
			kase = 1;
			count++;
			i++;
		}
		if(kase)
			block++;
		kase = 0;
		if(count > maxlen)
			maxlen = count;
		count = 0;
		while(a[i] == 'S' && i < n){
			kase = 1;
			count++;
			i++;
		}
		if(kase)
			block++;
		if(count == 1){
			kase = 0;
			maxlen1 = count;
			maxlen2 = 0;
			while(a[i] == 'G' && i < n){
				kase = 1;
				count++;
				i++;
			}
			if(kase)
				block++;
			maxlen2 = count
		}
	}
	printf("%d\n", block);
	return 0;
}