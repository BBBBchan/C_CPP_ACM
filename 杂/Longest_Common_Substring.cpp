#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;
set<string> setOflcs;
int Longest_Common_Substring(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int result = 0;
    dp = vector<vector<int>>(m+1, vector<int>(n+1));
    for(int i = 0; i < m+1; i++){
        for(int j = 0; j < n+1; j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > result)
                    result = dp[i][j]; // 存放LCS的长度
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}
void traceBack(string x, string y, int lcs_len){
    int m = x.length();
    int n = y.length();
    string strOflcs;
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if(dp[i][j] == lcs_len){
                int ii = i, jj = j;
                while(dp[ii][jj] >= 1){
                    strOflcs.push_back(x[ii-1]);
                    ii--;
                    jj--;
                }
                string str(strOflcs.rbegin(), strOflcs.rend()); 
                if((int)str.size() == lcs_len){
                    setOflcs.insert(str);
                    strOflcs.clear();                           
                }
            }
        }
    }
}

// 输出set
void print(){
    set<string>::iterator iter = setOflcs.begin();
    for(; iter != setOflcs.end(); iter++)
        cout << *iter << endl;
}
int main(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    int m = x.length();
    int n = y.length();
    int result = Longest_Common_Substring(x, y);
    cout << "result = " << result << endl;
    traceBack(x, y, result);
    print();
    return 0;
}