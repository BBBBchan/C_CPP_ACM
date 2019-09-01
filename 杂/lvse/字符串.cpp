#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <bits/stdc++.h>
using namespace std;
int nex[100005] , Next[100005];
class Solver {
    void getNext(string s, int nex[]) {
    int lenS = s.size();
    nex[0] = lenS;
    int p = 0;
    while (p+1 < lenS && s[p] == s[p+1]) p++;
    nex[1] = p;
    int k = 1, L;
    for (int i = 2; i < lenS; i++) {
        p = k + nex[k] - 1, L = nex[i-k];
        if (i + L <= p)
            nex[i] = L;
        else {
            int j = max(p-i+1, 0);
            while (i + j < lenS && s[i+j] == s[j]) j++;
            nex[i] = j, k = i;
        } 
    }
}
void GetNext(string s)
{
    int j,k;
    j=0;
    k=-1;
    Next[0]=-1;
    int wlen = s.size();
    while(j<wlen)
    {
        if(k==-1||s[j]==s[k])
        {
            Next[++j]=++k;
        }
        else k=Next[k];
    }
}
int KMP_count(string s, string p)
{
    int ans=0;
    int i,j=0;
    int wlen = s.size(), tlen = p.size();
    if(wlen==1&&tlen==1)
    {
        if(s[0]==p[0])return 1;
        else return 0;
    }
    GetNext(s);
    for(i=0;i<tlen;i++)
    {
        while(j>0&&p[i]!=s[j])
          j=Next[j];
        if(s[j]==p[i])j++;
        if(j==wlen)
        {
            ans++;
            j=Next[j];
        }
    }
    return ans;
}
public: vector<pair<int, int>> solve(string p) {
		/********** Begin **********/
        int len = p.size() ;
         getNext(p,nex);
         vector<pair<int,int>> fin;
    for(int i = len-1 ; i >=0 ; i--){
        if(nex[i] == len-i){
            memset(Next, 0, sizeof(Next));
            pair<int, int> temp;
            temp.first = len-i;
            string s = p.substr(0,len-i);
            temp.second = KMP_count(s,p);
            fin.push_back(temp);
        }
    }
    return fin;
		/********** End **********/
	}
};

#endif
