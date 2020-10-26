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
int n, m, t;
LL dp[31][(1 << 15)];

bool valid (int s, int t)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool s1 = (s&(1 << i)), s2 = (s&(1 << (i + 1)));
        bool t1 = (t&(1 << i)), t2 = (t&(1 << (i + 1)));
        if (s1 == s2 && s2 == t1 && t1 == t2) return 0;
    }
    return 1;
}

LL go (int u, int state)
{
    if (u == 1) return 1;
    if (dp[u][state] != -1) return dp[u][state];
    dp[u][state] = 0;

    for (int i = 0; i < (1 << n); ++i) if (valid(state, i))
        dp[u][state] += go(u - 1, i);

    return dp[u][state];
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        if (m < n) swap(m, n);
        memset(dp, -1, sizeof(dp));

        LL res = 0;
        for (int i = 0; i < (1 << n); ++i)
        res += go(m, i);

        printf("%lli\n", res);
    }
}
