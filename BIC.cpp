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
const LL MOD = 1000000000;
int d[10001], low[10001], number[10001], st[10001], k, t, n, m;
LL dp[10001], res;
vector <int> a[10001], aa[10001], aRe[10001];
bool vist[10001], p[10001][10001], cycle, M;

void dfs (int u)
{
    vist[u] = 1;
    d[u] = 1;
    for (int v : aRe[u]) if (!vist[v])
        dfs(v);
}

void tarjan (int u)
{
    low[u] = number[u] = ++t;
    st[++k] = u;

    for (int v : aa[u]) if (!vist[v])
    {
        if (!number[v])
        {
            tarjan(v);
            if (cycle) return;
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], number[v]);
    }

    if (low[u] == number[u])
    {
        int x = 0;
        bool ok = (st[k] != u);
        if (ok)
        {
            while (x != u)
            {
                x = st[k--];
                vist[x] = 1;
                if (d[x]) cycle = 1;
            }
        }
        else
        {
            vist[st[k]] = 1;
            --k;
        }
    }
}

LL go (int u)
{
    if (dp[u] != -1) return dp[u];
    dp[u] = 0;
    for (int v : a[u])
    {
        dp[u] += go(v);
        if (dp[u] > 999999999) M = 1;
        dp[u] %= MOD;
    }

    return dp[u];
}

void process()
{
    if (!M) return;
    LL tmp = res;
    int k = 0;
    while (tmp)
    {
        ++k;
        tmp /= 10;
    }
    for (int i = 1; i <= (9 - k); ++i)
        printf("0");
}

void load()
{
    scanf("%d%d", &n, &m);
    int u, v;
    REP(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        if (!p[u][v])
        {
            aa[u].push_back(v);
            aRe[v].push_back(u);
            p[u][v] = 1;
        }
        a[u].push_back(v);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    load();

    dfs(2);
    memset(vist, 0, sizeof(vist));
    tarjan(1);

    if (cycle) printf("inf");
    else
    {
        memset(dp, -1, sizeof(dp));
        dp[2] = 1;
        res = go(1);
        process();
        printf("%lli", res);
    }
}
