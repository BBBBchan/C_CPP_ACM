#include <cstdio>
#include <cstring>
char max[120],a[120];
int max_len = 0, max_num = 0;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", a);
		int now_len = strlen(a);
		if(now_len > max_len){
			for(int i = 0; i < now_len; i++)
				max[i] = a[i];
			a[now_len] = '\0';
			max_len = now_len;
			max_num = i+1;
		}
		else if(now_len == max_len){
			for(int k = 0; k < now_len; k++){
				if(a[k] > max[k]){
					for(int j = 0; j < now_len; j++)
						max[j] = a[j];
					a[now_len] = '\0';
					max_num = i+1;
					break;
				}
				else if(a[k] < max[k])
					break;
			}
		}
	}
	printf("%d\n", max_num);
	printf("%s", max);
	return 0;
}