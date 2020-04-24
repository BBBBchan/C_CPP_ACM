/*
在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过 n−1 次合并之后， 就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
因为还要花大力气把这些果子搬回家，所以多多在合并果子时要尽可能地节省体力。假定每个果子重量都为 1 ，并且已知果子的种类 数和每种果子的数目，你的任务是设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[20009];
bool cmp(int a, int b){
    return a>b;
}
int main()
{
    int n;
    scanf("%d", &n);
    int temp = n;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //利用快速排序初始化数据
    sort(a,a+n,cmp);
    int ans = 0;
    for(int i = 0; i < temp-1; i++){
    	// 合并前两堆果子
        a[n-2] = a[n-1]+a[n-2];
        //结果更新
        ans+=a[n-2];
        int temp1 = n-3, temp2 = n-2;
        //找到合适的位置插入新数据
        while(temp1>=0 && a[temp1] < a[temp2]){
            swap(a[temp1], a[temp2]);
            temp1--;
            temp2--;
        }
        //每次合并后果子堆的数量减少   
        n--;
    }
    printf("%d", ans);
    return 0;
}
 