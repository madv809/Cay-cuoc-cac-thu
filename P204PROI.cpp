#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
 
#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array
 
using namespace std;
 
const int mxn = 2e6 + 5;
const LL INF = 1e18;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
LL dp[mxn], f[mxn], rase[mxn], n, k;
 
LL pow_mod(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b&1) (res *= a)%=MOD;
        (a *= a)%=MOD;
        b >>= 1;
    }
    return res;
}
 
LL comb (LL n, LL k)
{
    if (n < k) return 0;
    return (f[n]*rase[n - k]%MOD*rase[k]%MOD);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> k;
    f[0] = f[1] = 1;
    REP(i, 2, n) (f[i] = f[i - 1]*(LL)i)%=MOD;
    rase[n] = pow_mod(f[n], MOD - 2);
    for (int i = n - 1; i >= 1; --i) (rase[i] = rase[i + 1]*(LL)(i + 1))%=MOD;
    rase[0] = 1;
 
    for (LL i = n; i >= 1; --i)
    {
        if (n%i != 0) continue;
        dp[i] = comb(n/i - 1, k - 1);
        LL xx = dp[i];
        for (LL x = 2*i; x <= n; x += i)
        {
            dp[i] -= dp[x];
            if (dp[i] < 0) dp[i] += MOD;
        }
        //cout << i << " : " << dp[i] << endl;
    }
 
    cout << dp[1];
}
 
