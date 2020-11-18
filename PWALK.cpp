#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>

using namespace std;
int sp[1001][20], in[2001], out[2001], par[2001], x, k, n, q;
LL cr[1001];
vector <int> a[1001], c[1001];

void dfs (int p, int u, LL w)
{
    par[u] = p; cr[u] = w; in[u] = ++k;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (par[v]) continue;
        dfs(u, v, w + c[u][i]);
    }
    out[u] = ++k;
}

void preCal()
{
    REP(i, 1, n) sp[i][0] = par[i];
    REP(j, 1, x) REP(i, 1, n) sp[i][j] = sp[sp[i][j - 1]][j - 1];
}

bool ispar (int u, int v)
{
    return (in[u] < in[v] && out[u] > out[v]);
}

int lca (int u, int v)
{
    if (ispar(u, v)) return u;
    if (ispar(v, u)) return v;
    for (int i = x; i >= 0; --i) if (!ispar(sp[u][i], v)) u = sp[u][i];
    return par[u];
}

LL gett (int u, int v)
{
    int l = lca(u, v);
    return (cr[u] + cr[v] - 2*cr[l]);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    int u, v, w;
    FOR(i, 1, n){ scanf("%d%d%d", &u, &v, &w);a[u].pb(v);a[v].pb(u);c[u].pb(w);c[v].pb(w);}
    dfs(-1, 1, 0);
    while ((1 << (x + 1)) <= n) ++x;
    par[1] = 0; in[0] = -9999999; out[0] = 9999999;
    preCal();
    REP(i, 1, q)
    {
        scanf("%d%d", &u, &v);
        printf("%lli\n", gett(u, v));
    }
}
