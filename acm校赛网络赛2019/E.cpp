#include<cstdio>
int main()
{
    int m;
    while(scanf("%d", &m) != EOF){
        int s = 0, sum = 0, count = m;
        for(int i = 1; i <= m; i++)
        {
            int temp;
            scanf("%d", &temp);
            if(temp == 0){
                count --;
                continue;
            }
            s ^= temp;
            if(temp > 1)
                sum++;
        }
        if((sum == 0 && count & 1) || (!s && sum >= 2))
            printf("orzwang9897\n");
        else
            printf("orzwym6912\n");
    }
    return 0;
}