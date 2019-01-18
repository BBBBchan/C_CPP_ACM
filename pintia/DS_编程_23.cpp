#include <cstdio>
struct node{
	int data;
	int next;
}a[100005];
int main(int argc, char const *argv[])
{
	int start, n;
	scanf("%d %d", &start, &n);
	for(int i = 0; i < n; i++){
		node temp;
		int address;
		scanf("%d %d %d", &address, &temp.data, &temp.next);
		a[address] = temp;
	}
	int aa[100005], b[100005],count=0;
	while(start != -1){
		aa[count] = start;
		count++;
		start = a[start].next;
	}
	int l = 0, r = count - 1, x = 0;
	while(l <= r){
		if(l == r){
			b[x] = aa[l];
			l++;
			x++;
		}
		else{
			b[x] = aa[r];
			r--;
			x++;
			b[x] = aa[l];
			l++;
			x++;
		}
	}
	for(int i = 0; i < x-1; i++)
		printf("%05d %d %05d\n", b[i], a[b[i]].data, b[i+1]);
	printf("%05d %d %d\n", b[x-1], a[b[x-1]].data, -1);
	return 0;
}