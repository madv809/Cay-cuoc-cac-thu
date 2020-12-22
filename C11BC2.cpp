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
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
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
int p[mxn], t;
vector<int> a[mxn];

void dfs (int par, int u)
{
    p[u] = t;
    for (int v : a[u]) if (v != par)
        dfs(u, v);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m; cin >> n >> m;
    REP(i, 2, n)
    {
        int v, k; cin >> v >> k;
        if (k == 1) {a[i].pb(v); a[v].pb(i);}
    }
    REP(i, 1, n) if (!p[i]) {++t; dfs(0, i);}
    REP(i, 1, m)
    {
        int u, v; cin >> u >> v;
        if (p[u] == p[v]) cout << "NO\n";
        else cout << "YES\n";
    }
}
