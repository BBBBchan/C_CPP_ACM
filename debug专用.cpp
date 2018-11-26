#include<stdio.h>
int main(void)
{
    int n, m;
    scanf("%d%d",&n,&m);
    char map[105][105];
    for (int i = 2; i < n + 2; i++){
        for (int j = 2; j < m + 2; j++){
            scanf("%c",&map[i][j]);
        }
    }
    for (int i = 2; i < n + 2; i++)
        for (int j = 2; j < m + 2; j++)
        {
            if (map[i][j] != '*')
                {
                    map[i][j] = '0';
                }
        }
        
    for (int i = 2; i < n + 2; i++)
        for (int j = 1; j < m + 2; j++)
        {
            if (map[i][j] == '*')
                {
                    if(map[i - 1][j - 1] != '*')
                        map[i - 1][j - 1]++;
                    if(map[i - 1][j] != '*')
                        map[i - 1][j]++;
                    if(map[i - 1][j + 1] != '*')
                        map[i - 1][j + 1]++;
                    if(map[i][j - 1] != '*')
                        map[i][j - 1]++;
                    if (map[i][j + 1] != '*')
                        map[i][j + 1]++;
                    if(map[i + 1][j - 1] != '*')
                        map[i + 1][j - 1]++;
                    if(map[i + 1][j] != '*')
                        map[i + 1][j]++;
                    if(map[i + 1][j + 1] != '*')
                        map[i + 1][j + 1]++;
                }
        }
    for (int i = 2; i < n + 2; i++)
    {
        for (int j = 2; j < m + 2; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
        return 0;
}