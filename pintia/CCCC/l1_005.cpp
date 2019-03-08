#include <cstdio>
struct {
	char num[20];
	int test;
	int exam;
}student[1005];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s %d %d", student[i].num, &student[i].test, &student[i].exam);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int temp;
		scanf("%d", &temp);
		for(int j = 0; j < n; j++)
			if(temp == student[j].test){
				printf("%s %d\n", student[j].num, student[j].exam);
				break;
			}
	}
	return 0;
}