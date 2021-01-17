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
 
const int mxn = 2e5 + 5;
const int INF = 1e9;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
int g[mxn], in[mxn], en[mxn], n, m, log2n, t;
vector<int> ac[mxn];
pii f[31][mxn];
bool no[mxn];
struct node
{
    int u, v, c;
} a[mxn];
 
bool cmp(node a, node b)
{
    return (a.c > b.c);
}
 
int findd (int u)
{
    if (g[u] < 0) return u;
    return (g[u] = findd(g[u]));
}
 
void uni(int u, int v, int c)
{
    if (g[u] <= g[v])
    {
        ac[u].pb(v);
        f[0][v].X = u;
        f[0][v].Y = c;
        g[u] += g[v];
        g[v] = u;
    }
    else
    {
        ac[v].pb(u);
        f[0][u].X = v;
        f[0][u].Y = c;
        g[v] += g[u];
        g[u] = v;
    }
}
 
void dfs (int u)
{
    in[u] = ++t;
    for (int v : ac[u])
        dfs(v);
    en[u] = t;
}
 
bool is_par(int u, int v)
{
    return (in[u] <= in[v] && en[u] >= en[v]);
}
 
int lca (int u, int v)
{
    if (is_par(u, v)) return u;
    if (is_par(v, u)) return v;
 
    for (int i = log2n; i >= 0; --i)
        if (!is_par(f[i][u].X, v)) u = f[i][u].X;
 
    return f[0][u].X;
}
 
int get (int u, int v)
{
    int x = lca(u, v);
    int res = INF;
 
    if (u != x)
    {
        for (int i = log2n; i >= 0; --i)
            if (!is_par(f[i][u].X, x))
            {
                res = min(res, f[i][u].Y);
                u = f[i][u].X;
            }
        res = min(res, f[0][u].Y);
    }
 
    if (v != x)
    {
        for (int i = log2n; i >= 0; --i)
            if (!is_par(f[i][v].X, x))
            {
                res = min(res, f[i][v].Y);
                v = f[i][v].X;
            }
        res = min(res, f[0][v].Y);
    }
    return res;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m;
    REP(i, 1, m) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].c);
    sort(a + 1, a + m + 1, cmp);
    memset(g, -1, sizeof(g));
    int r = 0;
    REP(i, 1, m)
    {
        int x = findd(a[i].u), y = findd(a[i].v);
        if (x != y)
        {
            no[i] = 1;
            uni(x, y, a[i].c);
            if (++r == n - 1) break;
            //cout << a[i].u << ' ' << a[i].v << endl;
        }
    }
 
    REP(i, 1, n) if (g[i] < 0)
    {
        dfs(i);
        break;
    }
    in[0] = -INF; en[0] = INF;
 
    log2n = (int)log2(n);
    REP(i, 1, log2n) REP(j, 1, n)
    {
        f[i][j].X = f[i - 1][f[i - 1][j].X].X;
        f[i][j].Y = min(f[i - 1][j].Y, f[i - 1][f[i- 1][j].X].Y);
    }
 
    LL res = 0;
    REP(i, 1, m) if (!no[i])
        res += (LL)(get(a[i].u, a[i].v) - a[i].c);
 
    cout << res;
}
 
