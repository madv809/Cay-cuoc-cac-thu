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

using namespace std;
const int INF = 1000000009;
int dp[101][10001], n, k, r, t, cbest = INF;
int best = INF;
vector <int> a[101], l[101], c[101];
bool vist[101];

int go (int u, int cost)
{
    if (cost < 0) return INF;
    if (u == 1)
        return 0;
    if (dp[u][cost] != -1) return dp[u][cost];
    dp[u][cost] = INF;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        dp[u][cost] = min(dp[u][cost], l[u][i] + go(v, cost - c[u][i]));
    }
    return dp[u][cost];
}

void reset()
{
    FOR(i, 1, n)
    {
        a[i].clear();
        l[i].clear();
        c[i].clear();
    }
    memset(dp, -1, sizeof(dp));
    best = INF;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    int u, v, lt, ct;
    while(t--)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        scanf("%d", &r);
        reset();
        FOR(i, 1, r)
        {
            scanf("%d%d", &u, &v);
            scanf("%d%d", &lt, &ct);
            a[v].push_back(u);
            l[v].push_back(lt);
            c[v].push_back(ct);
        }
        best = go(n, k);
        if (best < INF) printf("%d\n", best);
        else printf("-1\n");
    }
}
