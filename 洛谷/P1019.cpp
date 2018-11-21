#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct Words{
	char data[100];
	int len;
	int times;
};
vector< vector <Words>> G(30);
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		Words w;
		scanf("%s", w.data);
		w.len = strlen(w.data);
		w.times = 0;
		if(w.data[0]-'a' != w.data[w.len-1]-'a')
			G[w.data[0]-'a'].push_back(w);
	}
	return 0;
}