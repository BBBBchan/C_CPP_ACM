/*
有n项工作，每项工作分别在si时间开始，在ti时间结束。
对于每项工作，你都可以选择参与与否。如果选择了参与，那么自始至终都必须全程参与。
此外，参与工作的时间段不能重叠（即使是开始的瞬间和结束的瞬间的重叠也是不允许的）。
你的目标是参与尽可能多的工作，那么最多能参与多少项工作呢？
*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct work{
    int s;
    int e;
}a[1000008];
bool cmp(work a, work b){
    return a.e<b.e;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i].s, &a[i].e);
    }
    // 按结束时间排序
    sort(a,a+n,cmp);
    //维护当前任务结束时间和总任务数量
    int now = a[0].e , ans = 1;
    for(int i = 1; i < n; i++){
        //当前任务是否结束
        if(a[i].s<now)
            continue;
        else{
            //接受新任务
            ans++;
            now = a[i].e;
        }
    }
    printf("%d", ans);
    return 0;
}