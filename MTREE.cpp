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
const LL MOD = 1e9+7; const int mxn = 2e5 + 5;
struct nodee
{
    LL g;
} node[mxn];
vector<int> a[mxn]; vector<LL> c[mxn];

void dfs (int p, int u)
{
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i]; if (v == p) continue;
        dfs(u, v);
        (node[u].g += c[u][i]*(node[v].g + 1)%MOD)%MOD;
    }
}

void dfs2 (int p, int u)
{
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i]; if (v == p) continue;

        LL x = (node[u].g  - c[u][i]*(node[v].g + 1)%MOD + MOD)%MOD;
        (node[v].g += c[u][i]*(x + 1)%MOD)%=MOD;
        dfs2(u, v);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    FOR(i, 1, n)
    {
        int u, v; LL w;
        scanf("%d%d%lli", &u, &v, &w);
        w %= MOD;
        a[u].pb(v); a[v].pb(u);
        c[u].pb(w); c[v].pb(w);
    }
    dfs(0, 1);

    dfs2(0, 1);
    LL res = 0; REP(i, 1, n) (res+=node[i].g)%=MOD;
    cout << (res*((MOD + 1)/2)%MOD) << endl;
}
