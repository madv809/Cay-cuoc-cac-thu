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

const int mxn = 1e5 + 5;
const int INF = 1e9;
const LL BASE = 311;
int low[mxn], child[mxn], num[mxn], cut_node[mxn], en[mxn], in[mxn], t, n, m;
int sp[mxn][30], log2n;
vector<int> a[mxn];

void dfs (int p, int u)
{
    sp[u][0] = p;
    low[u] = num[u] = in[u] = ++t;
    for (int v : a[u]) if (v != p)
    {
        if (num[v]) {low[u] = min(low[u], num[v]); continue;}
        ++child[u];
        dfs(u, v);
        low[u] = min(low[u], low[v]);

        if (u == 1 && child[u] >= 2) cut_node[u] = 1;
        else if (low[v] >= num[u]) cut_node[u] = 1;
    }
    en[u] = t;
}

bool is_par (int u, int v)  // return true nếu u là cha của v
{
    return (in[u] <= in[v] && en[u] >= en[v]);
}

int find_par (int v, int c)
{
    for (int i = log2n; i >= 0; --i)
            if (!is_par(sp[v][i], c) && is_par(c, sp[v][i])) v = sp[v][i];
    return v;
}

bool solve (int u, int v, int g1, int g2)
{
    if (is_par(g2, g1)) swap(g1, g2);
    if (low[g2] < num[g2]) return 1;
    if (u == g1 || u == g2 || v == g1 || v == g2) return 0;
    if (is_par(g1, u) == is_par(g1, v)) return 1;
    return 0;
}

bool solve2 (int u, int v, int c)
{
    if (!cut_node[c]) return 1;
    if (!is_par(c, u) && !is_par(c, v)) return 1;
    if (is_par(c, u) && is_par(c, v))
    {
        int x = find_par(u, c), y = find_par(v, c);
        if (x == y) return 1;
        if (low[x] < num[c] && low[y] < num[c]) return 1;
    }
    else
    {
        if (is_par(c, u)) swap(u, v);
        v = find_par(v, c);

        if (low[v] < num[c]) return 1;
    }
    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m;
    REP(i, 1, m){int u, v; scanf("%d%d", &u, &v); a[u].pb(v); a[v].pb(u);}

    dfs(0, 1); in[0] = -INF; en[0] = INF;
    log2n = (int)log2(n);
    REP(j, 1, log2n) REP(i, 1, n) sp[i][j] = sp[sp[i][j - 1]][j - 1];

    int q; cin >> q;
    REP(i, 1, q)
    {
        int x, a, b, g1, g2;
        cin >> x;
        if (x == 1)
        {
            scanf("%d%d%d%d", &a, &b, &g1, &g2);
            if (solve(a, b, g1, g2)) cout << "yes\n";
            else cout << "no\n";
        }
        else
        {
            scanf("%d%d%d", &a, &b, &g1);
            if (solve2(a, b, g1)) cout << "yes\n";
            else cout << "no\n";
        }
    }
    /*cout << low[12] << ' ' << en[12] << endl;
    cout << low[8] << ' ' << en[8] << endl;
    cout << low[9] << ' ' << en[9] << endl;
    cout << is_par(sp[13][0], 8) << ' ' << is_par(8, sp[13][0]);*/
}
