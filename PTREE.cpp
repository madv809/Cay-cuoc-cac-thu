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
const int INF = 1000000009;
int dp[201][201], trace[201][201], parr[201], c[201], n, p;
vector <int> a[201];
bool ch[201];

void go (int par, int u)
{
    dp[u][1] = c[u];

    for (int v : a[u]) if (v != par)
    {
        parr[v] = u;
        go(u, v);
        for (int j = p; j >= 2; --j)
            for (int k = 1; k <= j - 1; ++k)
            {
                if (dp[u][j] < dp[v][k] + dp[u][j - k])
                {
                    dp[u][j] = dp[v][k] + dp[u][j - k];
                    trace[v][j] = k;
                }
            }
    }
}

void goFinal (int par, int u, int c)
{
    reverse(a[u].begin(), a[u].end());
    ch[u] = 1;
    for (int v : a[u]) if (v != par)
    {
        if (trace[v][c])
        {
            goFinal(u, v, trace[v][c]);
            c -= trace[v][c];
        }
    }
}

int main()
{
    freopen("D:\\test.txt", "r", stdin);
    freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &p);
    REP(i, 1, n) scanf("%d", &c[i]);
    int u, v;
    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    REP(i, 1, n)
        REP(j, 2, p) dp[i][j] = -INF;

    go(0, 1);
    int best = -INF, tmp = 0;
    REP(i, 1, n)
    {
        if (best < dp[i][p])
        {
            best = dp[i][p];
            tmp = i;
        }
    }

    //printf("%d\n", best);
    goFinal(parr[tmp], tmp, p);
    REP(i, 1, n) if (ch[i]) printf("%d ", i);
}
