#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
 
struct mon
{
    long long hp;
    long long atk;
    long long value;
}monsters[100050];
 
bool cmp(mon a, mon b){
    return (double)a.atk/(double)a.value > (double)b.atk/(double)b.value ;
}
 
int main(int argc, char const *argv[]){
    int t;
    scanf("%d",&t);
    int coun = 0;
    while(t--){
    	coun++;
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
        	scanf("%lld %lld", &monsters[i].hp, &monsters[i].atk);
        }
        long long sum = 0;
        for(int i = 0; i < n; i++){
            long long damge = 1, times = 0;
            while(monsters[i].hp > 0){
                monsters[i].hp -= damge;
                damge++;
                times++;
            }
            monsters[i].value = times;
        }
        sort(monsters,monsters+n,cmp);
        long long times=0;
        for(int i = 0; i < n; i++){
            sum += monsters[i].atk * (times + monsters[i].value);
            times += monsters[i].value;
        }
        printf("Case #%d: %lld\n", coun, sum);
    }
    return 0;
}