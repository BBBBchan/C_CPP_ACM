#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <cstring>
#include <vector>
using namespace std;
int next1[100055];
int next2[100055];

void get_next(string P, int next[]){
    int p_len = P.size();
    int i = 0;   // P 的下标
    int j = -1;  
    next[0] = -1;
    while (i < p_len){
        if (j == -1 || P[i] == P[j]){
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
/* 在 S 中找到 P 第一次出现的位置，返回位置 */
int KMP(string S, string P, int next[]){
    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = S.size();
    int p_len = P.size();
    while (i < s_len && j < p_len){
        if (j == -1 || S[i] == P[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j == p_len)  // 匹配成功
        return i - j; 
    return -1;
}

int main(int argc, char const *argv[])
{
	int q;
	string t;
	cin >> t;
	get_next(t, next1);
	scanf("%d", &q);
	while(q--){
		string s;
		cin >> s;
		if(s.size() < t.size()){
			memset(next2, 0, sizeof(next2));
			get_next(s,next2);
			if(KMP(t,s,next2) == -1){
				printf("oh, child!\n");
			}
			else{
				printf("my child!\n");
			}
		}
		else if(s.size() > t.size()){
			
			if(KMP(s,t,next1) == -1){
				printf("senior!\n");
			}
			else{
				printf("my teacher!\n");
			}
		}
		else if(s.size() == t.size()){
			if(s == t){
				printf("jntm!\n");
			}
			else{
				printf("friend!\n");
			}
		}
	}
	return 0;
}






