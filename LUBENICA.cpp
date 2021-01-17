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
int in[mxn], en[mxn], log2n, t, n, k;
vector<int> a[mxn], x[mxn];
struct node
{
    int p = 0, mi, mx;
} f[31][mxn];
 
void dfs (int p, int u)
{
    in[u] = ++t;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (v == p) continue;
        f[0][v].p = u;
        f[0][v].mi = f[0][v].mx = x[u][i];
        dfs(u, v);
    }
    en[u] = t;
}
 
bool is_par(int u, int v)
{
    return (in[u] <= in[v] && en[u] >= en[v]);
}
 
int lca(int u, int v)
{
    if (is_par(u, v)) return u;
    if (is_par(v, u)) return v;
 
    for (int i = log2n; i >= 0; --i)
        if (!is_par(f[i][u].p, v)) u = f[i][u].p;
 
    return f[0][u].p;
}
 
void get(int u, int v)
{
    if (u == v) {cout << "0 0/n"; return;}
    int x = lca(u, v);
    int rmi = INF, rmx = -INF;
 
    if (u != x)
    {
        int kk = log2n;
        for (int i = log2n; i >= 0; --i) if (!is_par(f[i][u].p, x))
        {
            rmi = min(rmi, f[i][u].mi);
            rmx = max(rmx, f[i][u].mx);
            u = f[i][u].p;
        }
        rmi = min(rmi, f[0][u].mi); rmx = max(rmx, f[0][u].mx);
    }
 
    if (v != x)
    {
        for (int i = log2n; i >= 0; --i) if (!is_par(f[i][v].p, x))
        {
            rmi = min(rmi, f[i][v].mi);
            rmx = max(rmx, f[i][v].mx);
            v = f[i][v].p;
        }
        rmi = min(rmi, f[0][v].mi); rmx = max(rmx, f[0][v].mx);
    }
 
    cout << rmi << ' ' << rmx << endl;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        a[u].pb(v); a[v].pb(u);
        x[u].pb(c); x[v].pb(c);
    }
 
    dfs(0, 1);
    in[0] = -INF; en[0] = INF;
    log2n = (int)log2(n);
    REP(i, 1, log2n) REP(j, 1, n)
    {
        f[i][j].p = f[i - 1][f[i - 1][j].p].p;
        f[i][j].mi = min(f[i - 1][j].mi, f[i - 1][f[i - 1][j].p].mi);
        f[i][j].mx = max(f[i - 1][j].mx, f[i - 1][f[i - 1][j].p].mx);
    }
 
    cin >> k;
    REP(i, 1, k)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        get(u, v);
    }
}
 
