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
const int mxn = 1e5 + 5;
const LL INF = 1e9;
const LL MOD = 790972;
const int BASE = 10000;
 
pLL a[mxn];
LL dp[mxn][55], re_dp[mxn][55];
int n, k;
 
LL Solve (int l, int r)
{
    if (r - l + 1 < k) return 0;
    memset(re_dp, 0, sizeof(re_dp));
    REP(i, l, r) re_dp[i][1] = re_dp[i - 1][1] + a[i].Y;
    REP(j, 2, k) for (int i = l + 1; i <= r; ++i)
        (re_dp[i][j] = re_dp[i - 1][j] + re_dp[i - 1][j - 1]*a[i].Y)%=MOD;
    return re_dp[r][k];
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> k;
    REP(i, 1, n) scanf("%lli%lli", &a[i].Y, &a[i].X);
    sort(a + 1, a + n + 1);
    dp[1][1] = a[1].Y;
    int x = 0;
    REP(i, 1, n) dp[i][1] = dp[i - 1][1] + a[i].Y;
    REP(j, 2, k) REP(i, 2, n)
        (dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]*a[i].Y)%=MOD;
    int i = 1;
    a[n + 1].X = -1;
    for (int j = 2; j <= n + 1; ++j) if (a[j].X != a[j - 1].X)
    {
        LL xx = dp[n][k];
        ((dp[n][k] -= Solve(i, j - 1))+=MOD)%=MOD;
        xx = dp[n][k];
        i = j;
    }
    cout << dp[n][k];
}
