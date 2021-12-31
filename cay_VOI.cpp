#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define LL long long
#define RED(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for(int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b - 1); ++i)
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define piL pair<int, LL>
#define pLi pair<LL, int>
#define X first
#define Y second
#define ci const int
#define cLL const LL

#define pb push_back
#define ef else if
using namespace std;
const int mxn = 2e5 + 5;
const int mxk = 1e7;
const int S = 200;
const long double eps = 1e-10;
const LL INF = 1e18;
const int lg = 16;
const LL base = 311;
const LL inv_base = 787781356;
const LL MOD = 1e9 + 7;
vector<int> a[mxn];
int deep[mxn], sz[mxn], d, n, max_deep;
LL Hash[mxn], reHash[mxn], val[mxn], pow_base[mxn];
bool dead[mxn];
unordered_set<int> type[mxn];
string s;

void calc_something()
{
    cin >> n >> s;
    REP(i, 1, n) val[i] = (int)s[i - 1];
    int u, v; int nn = n;
    FOR(i, 1, nn)
    {
        cin >> u >> v;
        val[++n] = 43;
        a[u].pb(n); a[n].pb(u);
        a[n].pb(v); a[v].pb(n);
    }
    REP(i, 1, nn) if (a[i].size() == 1)
    {
        val[++n] = 43;
        a[i].pb(n);
    }

    pow_base[0] = 1;
    REP(i, 1, n) pow_base[i] = base*pow_base[i - 1]%MOD;
    deep[0] = -1;
}

void dfs_size(int u, int p, int deep)
{
    d = max(d, deep);
    sz[u] = 1;
    for (int v : a[u]) if (v != p && !dead[v])
    {
        dfs_size(v, u, deep + 1);
        sz[u] += sz[v];
    }
}

int find_centroid(int u, int p, int len)
{
    d = 0;
    dfs_size(u, 0, 0);
    if (d*2 + 1 < len) return -1;
    int n = sz[u];

    while(1)
    {
        bool ok = 1;
        for (int v : a[u]) if (v != p && !dead[v] && sz[v] > n/2)
        {
            p = u;
            u = v;
            ok = 0;
            break;
        }

        if (ok) break;
    }

    return u;
}

void dfs_Hash(int u, int p, int len)
{
    deep[u] = deep[p] + 1;
    Hash[u] = (val[u] + Hash[p]*base)%MOD;
    reHash[u] = (val[u]*pow_base[len - 1] + reHash[p]*inv_base)%MOD;
    if (deep[u] == len - 1) return;

    for (int v : a[u]) if (v != p && !dead[v])
        dfs_Hash(v, u, len);
}

void dfs_update_Hash(int u, int p, int len)
{
    if (deep[u] == len - 1) return;
    max_deep = max(max_deep, deep[u]);
    type[deep[u] + 1].insert((Hash[u] - reHash[u] + MOD)%MOD);

    for (int v : a[u]) if (v != p && !dead[v])
        dfs_update_Hash(v, u, len);
}

bool dfs(int u, int p, int root, int len)
{
    if (deep[u] == len - 1)
        return (Hash[u] == reHash[u]);

    int tt = len - deep[u];
    LL x = (Hash[u] - val[root]*pow_base[deep[u]] + MOD*MOD)%MOD;
    x -= (reHash[u] - val[root]*pow_base[len - 1 - deep[u]] + MOD*MOD)%MOD;
    (x += MOD)%=MOD;
    if (type[tt].find(x) != type[tt].end()) return 1;

    for (int v  : a[u]) if (v != p && !dead[v])
        if (dfs(v, u, root, len)) return 1;

    return 0;
}

bool solve(int u, int len)
{
    u = find_centroid(u, 0, len);
    if (u == -1) return 0;
    dead[u] = 1;
    dfs_Hash(u, 0, len);

    max_deep = 0;
    for (int v : a[u]) if (!dead[v])
    {
        if (dfs(v, u, u, len))
        {
            REP(i, 1, max_deep) type[i].clear();
            return 1;
        }
        dfs_update_Hash(v, u, len);
    }
    REP(i, 1, max_deep + 1) type[i].clear();

    for (int v : a[u]) if (!dead[v])
        if (solve(v, len)) return 1;

    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(NULL);
    calc_something();

    int l = 1, r = (n - 1)/2, mid;
    while(l < r)
    {
        mid = (l + r + 1)>>1;
        REP(i, 1, n) dead[i] = 0;
        if (solve(1, mid*2 + 1)) l = mid;
        else r = mid - 1;
    }
    l = l*2 + 1;

    cout << (l/2);
}
