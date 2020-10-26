#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;
LL dp[17][(1 << 17)];
int a[17], n, k;

LL go (int u, int state)
{
    if (state == 0) return 1;
    if (dp[u][state] != -1) return dp[u][state];
    dp[u][state] = 0;
    FOR(i, 0, n) if ((state&(1 << i)) && abs(a[u] - a[i + 1]) > k)
        dp[u][state] += go(i + 1, state^(1 << i));
    return dp[u][state];
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, 1, n) scanf("%d", &a[i]);
    a[0] = 1000000000;
    memset(dp, -1, sizeof(dp));

    LL res = go(0, (1 << n) - 1);
    printf("%lli", res);
}
