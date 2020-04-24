/*
由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。帮助Marry乳业找到最优的牛奶采购方案.
Marry乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格是不同的。此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。每天Marry乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。
给出Marry乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。计算采购足够数量的牛奶所需的最小花费。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct sold{
    int num;
    int money;
}milk[5005];
bool cmp(sold a, sold b){
    return a.money<b.money;
}
int main(int argc, char const *argv[])
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &milk[i].money, &milk[i].num);
    }
    sort(milk, milk+m, cmp);
    int ans = 0,all=0,i=0;
    while(all<n){
        all+=milk[i].num;
        ans+=milk[i].num*milk[i].money;
        i++;
    }
    ans -=(all-n)*milk[--i].money;
    printf("%d", ans);
    return 0;
}