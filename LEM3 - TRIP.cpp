#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
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
const int INF = 1000000009;
int dp[17][(1 << 17)], c[17][17], n;
bool vist[17][(1 << 17)];

int go (int u, int state)
{
    if (vist[u][state]) return dp[u][state];
    vist[u][state] = 1;
    if (state == 0) return dp[u][state] = 0;
    dp[u][state] = INF;
    for (int i = 0; (1 << i) <= state; ++i) if ((state&(1 << i)))
    {
        dp[u][state] = min(dp[u][state], c[u][i] + go(i, (state^(1 << i))));
        int xx = dp[u][state];
    }
    return dp[u][state];
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int nn = n - 1;
    FOR(i, 0, nn)
        FOR(j, 0, nn) scanf("%d", &c[i][j]);
    int best = INF;
    for (int i = 0; i < n; ++i)
    {
        best = min(best, go(i, (((1 << n) - 1)^(1 << i))));
        int xx = best;
    }
    printf("%d", best);
}
