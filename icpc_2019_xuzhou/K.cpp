#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
struct pos{
	int x,y;
	bool operator < (const pos &o) const
	{
		if(x != o.x)
			return x < o.x;
		else
			return y < o.y;
	}
};

std::map<pos, int> xymap,xycmap;
int x[1005], y[1005]; 
int coun;
int nowans = 100000;
pos tem;
pos temp;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x[i], &y[i]);
		tem.x = x[i];
		tem.y = y[i]; 
		xymap[tem] = 1;
	}

	if(n == 1){
		printf("0");
	}
	else{
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			tem.x = x[i]+x[j];
			tem.y = y[i]+y[j];
			if(xycmap[tem] == 1){
				continue;
			}
			else{
				xycmap[tem] = 1;
			}
			coun = 0;
			for(int k = 0; k < n; k++){
				temp.x = tem.x-x[k];
				temp.y = tem.y-y[k];
				if(xymap[temp] == 1){
					coun++;
				}
			}
			nowans = min(nowans, n-coun);
		}
	}
	printf("%d", nowans);
}
	return 0;
}