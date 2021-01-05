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
 
const int mxn = 1e6 + 5;
const int INF = 1e9;
const LL BASE = 311;
set<int> a[mxn];
vector<int> b[mxn];
vector<pii> eri;
int low[mxn], num[mxn], gr[mxn], vis[mxn], t, n, m;
 
void dfs (int p, int u)
{
    low[u] = num[u] = ++t;
 
    vector<int> era;
    for (int v : a[u]) if (v != p)
    {
        if (num[v]) {low[u] = min(low[u], num[v]); continue;}
        dfs(u, v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[v]) // cung u v là cầu
            eri.push_back({u, v});
    }
}
 
void dfs2 (int p, int u)
{
    vis[u] = t;
    for (int v : a[u]) if (v != p && vis[v] != t)
        dfs2 (u, v);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m;
    REP(i, 1, m)
    {
        int u, v; cin >> u >> v;
        a[u].insert(v); a[v].insert(u);
    }
    dfs(0, 1); t = 0;
    REP(i, 1, n) if (!gr[i]) {++t; dfs2(0, i);}
    int res = 0; t = 0;
    for (pii i : eri)
    {
        int u = i.X, v = i.Y;
        ++t;
        a[u].erase(v); a[v].erase(u);
        dfs2(0, u);
        int x = 0;
        REP(i, 1, n) if (vis[i] == t) ++x;
        if (vis[v] != t) res += (n - x)*x;
        a[u].insert(v); a[v].insert(u);
    }
    cout << res;
}
