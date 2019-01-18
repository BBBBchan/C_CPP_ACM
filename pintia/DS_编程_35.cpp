#include <cstdio>
#include <algorithm>
using namespace std;
struct student{
	int num;
	char name[100];
	int score;
}data[100005];
bool cmp1(student a, student b){
	return a.num<b.num;
}
bool cmp2(student a, student b){
	int i = 0;
	while(a.name[i] == b.name[i]){
		if(a.name[i] == '\0')
			return a.num < b.num;
		i++;
	}
	return a.name[i] <= b.name[i];
}
bool cmp3(student a, student b){
	if(a.score != b.score)
		return a.score <= b.score;
	else
		return a.num < b.num;
}
int main(int argc, char const *argv[])
{
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d %s %d", &data[i].num, &data[i].name, &data[i].score);
	}
	if(c == 1){
		sort(data, data+n, cmp1);
	}
	else if(c == 2)
		sort(data, data+n, cmp2);
	else if(c == 3)
		sort(data, data+n, cmp3);
	for(int i = 0; i < n; i++)
		printf("%06d %s %d\n", data[i].num, data[i].name, data[i].score);
	return 0;
}