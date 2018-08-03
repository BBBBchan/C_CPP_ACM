#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cassert>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
const long long int  mod = (long long int)(1e9) + 7;
const int MAX = 10005;

long long int POW[MAX];

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

long long int qucik_pow(long long int x, long long int y)
{
    long long int  res = 1, tmp = x;
    while(y) {
        if(y & 1) res = res * tmp % mod;
        tmp = tmp * tmp % mod;
        y >>= 1;
    }
    return res;
}

int main()
{
    int n, t, T, cases = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &t, &n);
        POW[0] = 1;
        for(int i = 1; i <= n; ++i) POW[i] = POW[i - 1] * t % mod;
        long long int a = 0, b = 0;
        for(int i = 0; i < n; ++i) {
            a = ( a + POW[gcd(i, n)]) % mod;
        }
        if(n % 2) b = n * POW[(n + 1) / 2] % mod;
        else b = n / 2 * (POW[n / 2 + 1] + POW[n / 2]) % mod;
        long long int tmp = qucik_pow(2 * n, mod - 2);
        printf("Case #%d: %lld\n", ++cases, (a + b) * tmp % mod);
    }
    return 0;
}