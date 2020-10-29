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
const int INF = 100000009;
int dp[10001][15], colorr[10001], n;
vector <int> trace[10001][15], a[10001];

int go (int par, int u, int color)
{
    if (dp[u][color] != -1) return dp[u][color];

    dp[u][color] = color;
    int tmp;
    for (int v : a[u]) if (v != par)
    {
        int x = INF;
        REP(j, 1, 14) if (j != color)
        {
            if (x > go(u, v, j))
            {
                x = go(u, v, j);
                tmp = j;
            }
        }
        trace[u][color].push_back(tmp);

        dp[u][color] += x;
    }
    else trace[u][color].push_back(-1);
    return dp[u][color];
}

void goColor (int par, int u, int color)
{
    //if (u == 5) cout << a[u].size();
    colorr[u] = color;
    for (int i = 0; i < a[u].size(); ++i) if (a[u][i] != par)
        goColor(u, a[u][i], trace[u][color][i]);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int u, v;
    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    int best = INF, tmp;
    REP(i, 1, 14)
    {
        if (best > go(0, 1, i))
        {
            best = go(0, 1, i);
            tmp = i;
        }
    }

    goColor(0, 1, tmp);
    printf("%d\n", best);
    REP(i, 1, n) printf("%d\n", colorr[i]);
}
