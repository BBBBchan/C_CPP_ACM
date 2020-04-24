#include <cstdio>
int a[100005], rank[100005];
struct list
{
	int before;
	int num;
	int next;
}lists[100005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	lists[0].num = 0;
	lists[0].before = n-1;
	lists[0].next = 1;
	for(int i = 1; i < n-1; i++){
		lists[i].before = i-1;
		lists[i].num = i;
		lists[i].next = i+1;
	}
	lists[n-1].num = n-1;
	lists[n-1].before = n-2;
	lists[n-1].next = 0;
	int start = 0;
	int num = n;
	for(int i = 0; i < n; i++){
		if(a[i] == 0 || a[i]%num == 0){
			rank[lists[start].num] = n-i+1;
			printf("%d\n", lists[start].num);
			lists[lists[start].before].next = lists[lists[start].next].num;
			start++;
			num--;
		}
		else{
			int p = start;
			
			for(int j = 0; j < a[i]%num; j++){
				p = lists[lists[p].num].next;
				// printf("here%d \n", p);
			}
			p = lists[lists[p].num].next;
			rank[lists[p].num] = n-i+1;
			printf("start:%d p:%d out:%d\n", lists[start].num, p,lists[p].num);
			lists[lists[p].before].next = lists[lists[p].next].num;
			num--;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", rank[i]);
	}
	return 0;
}