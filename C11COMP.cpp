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
#include <bitset>
#include <unordered_map>

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
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
#define ef else if
#define lb lower_bound

using namespace std;
const int mxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 5;
int st[mxn], ed[mxn], sz[mxn], f[mxn], g[mxn], b[mxn], col[mxn], n, m, t, k;
vector<int> a[mxn];
bool vis[mxn];

void dfs1 (int u)
{
    st[u] = ++t;
    col[t] = b[u];
    sz[u] = 1;
    for (int v : a[u])
    {
        dfs1(v);
        sz[u] += sz[v];
    }
    ed[u] = t;
}

void dfs (int u, bool keep)
{
    int big_child = 0;
    for (int v : a[u]) if (sz[v] > sz[big_child]) big_child = v;

    for (int v : a[u]) if (v != big_child)
        dfs(v, 0);
    if (big_child != 0) dfs(big_child, 1);
    for (int v : a[u]) if (v != big_child)
    {
        REP(x, st[v], ed[v]) ++g[col[x]];
    }
    ++g[b[u]];

    REP(i, st[u], ed[u]) if (!vis[col[i]] && g[col[i]] <= k)
    {
        ++f[u];
        vis[col[i]] = 1;
    }
    REP(i, st[u], ed[u]) vis[col[i]] = 0;

    if (!keep)
        REP(i, st[u], ed[u]) g[col[i]] = 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m >> k;
    REP(i, 2, n)
    {
        int x; cin >> x;
        a[x].pb(i);
    }

    REP(i, 1, n) cin >> b[i];

    dfs1(1);
    dfs(1, 1);

    int q;
    cin >> q;
    REP(i, 1, q)
    {
        int x; cin >> x;
        cout << f[x] << endl;
    }
}
