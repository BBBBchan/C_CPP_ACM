#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	string s, t;
	cin << s;
	cin << t;
	int pos = 0;
	for(int i = 0; i < m; i++){
		for(int j = pos; j < n; j++){
			if(s[j] >  t[i]){
				break
			}
		}
	}
	return 0;
}