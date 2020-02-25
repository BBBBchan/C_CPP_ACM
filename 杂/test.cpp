#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include <map>
#define MAXN 1000100

using namespace std;

int n, m, num, tans;
int a[MAXN], cans[MAXN], coun[MAXN];
struct point{
    int l, r, id, pos, ans;       
}po[MAXN];
bool cmp1(point i, point j){
    if(i.pos == j.pos)
        return i.r < j.r;
    else 
        return i.pos < j.pos;     
}
bool cmp2(point i, point j){
    return i.id < j.id;     
}

void remove(int x){
    cans[a[x]]--;
    if(cans[a[x]] == 2)
        tans--;            
   }
void add(int x){
    cans[a[x]]++;
    if(cans[a[x]] == 3)
        tans++;          
   }


int main(){
    int i,j,k;
    scanf("%d", &n);
    int block = int(sqrt(double(n)));
    for(i = 1; i <= n; i++)
       scanf("%d", &a[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i++)
       scanf("%d%d",&po[i].l, &po[i].r);

    for(int i = 1; i <= m; i++){
        std::map<int, bool> times;
        for(int j = po[i].l; j <= po[i].r; j++ ){
            if(times[a[j]] == true)
                continue;
            else {
                times[a[j]] = true;
                coun[i]++;
            }
        }
    }

    for(i = 1; i <= m; i++)
        po[i].id=i; 
    for(i = 1; i <= m; i++){
        po[i].pos = po[i].l/block;
        num=max(num, po[i].pos);
    }
    sort(po+1,po+m+1,cmp1);
    int cl=1, cr=1;
    cans[a[cl]]=1;
    for(i=1; i <= m; i++){
        while(cl < po[i].l){
            remove(cl);
            cl++;
        }   
        while(cl > po[i].l){
            cl--;
            add(cl);
        } 
        while(cr < po[i].r){
            cr++;
            add(cr);
        } 
        while(cr > po[i].r){
            remove(cr);
            cr--;
        }        
        po[i].ans = tans; 
    }     
    sort(po+1,po+m+1,cmp2);
    for(int i = 1; i <= m; i++){
        po[i].ans += coun[i];
    }
    for(i = 1; i <= m; i++)
        cout<< po[i].ans <<endl;
    return 0;
}
/*
5
5 3 3 1 3
3
1 4
1 2
2 5
*/