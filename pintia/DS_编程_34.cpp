#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct word{
	char a[100];
}words[100];
bool cmp(word x, word y){
	int i = 0;
	while(x.a[i] == y.a[i]){
		i++;
		continue;
	}
	return x.a[i] < y.a[i];
}
int main(int argc, char const *argv[])
{
	for(int i = 0; i < 5; i++){
		scanf("%s", words[i].a);
	}
	sort(words,words+5,cmp);
	printf("After sorted:\n");
	for(int i = 0; i < 5; i++)
		printf("%s\n", words[i].a);
	return 0;
}