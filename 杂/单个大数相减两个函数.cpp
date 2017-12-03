#include <stdio.h>
#include <string.h>
 
// 从str1中查找str2的个数，并返回
int findChildCnt(char* str1, char* str2)
{
    int len = strlen(str2);
    int cnt = 0;
    while (str1 = strstr(str1, str2)) // 如果查找到,则执行循环，否则为空退出循环
    {
        cnt++; // 统计次数
        str1 += len; // 加上偏移量，即移除str2
    }
    return cnt;
}
 
int main()
{
    char str1[100000], str2[5];
    gets(str1);
    str2 = "QAQ";
    printf("Child Cnt: %d\n", findChildCnt(str1, str2));
    return 0;
}