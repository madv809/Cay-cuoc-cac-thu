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
#define one "bridge"
#define two "penguins"

using namespace std;
const int mxn = 3e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 7;
pair<int, pii> Q[10*mxn];
vector<int> adj[mxn];
bool vis[mxn];
int pa[30][mxn], seg[4*mxn], a[mxn], b[mxn], head[mxn], Head[mxn], st[mxn], ed[mxn], sz[mxn], ra[mxn], pos[mxn], n, q, nHead, nBase, log2n, t;

bool is_par(int u, int v) // u là cha của v
{
    return (st[u] <= st[v] && ed[u] >= ed[v]);
}

int lca(int u, int v)
{
    if (is_par(u, v)) return u;
    ef (is_par(v, u)) return v;

    for (int i = log2n; i >= 0; --i) if (!is_par(pa[i][u], v))
        u = pa[i][u];
    return pa[0][u];
}

int findd(int u)
{
    if (ra[u] < 0) return u;
    return (ra[u] = findd(ra[u]));
}

void uni(int u, int v)
{
    if (ra[u] < ra[v])
    {
        ra[u] += ra[v];
        ra[v] = u;
    }
    else
    {
        ra[v] += ra[u];
        ra[u] = v;
    }
}

void dfs1(int u, int p)
{
    pa[0][u] = p; vis[u] = sz[u] = 1;
    st[u] = ++t;
    for (int v : adj[u]) if (!vis[v])
    {
        dfs1(v, u);
        sz[u] += sz[v];
    }
    ed[u] = t;
}

void dfs(int u, int p, bool x) // nHead : index chuỗi, nBase : vị trí khi trải phẳng
{
    vis[u] = 1;
    pos[u] = ++nBase; b[nBase] = a[u];
    if (x == 0) // đầu chuỗi
    {
        head[++nHead] = u; // u là node đầu chuỗi
    }
    Head[u] = nHead; // u đang nằm ở chuỗi nào

    int big_Child = 0;

    for (int v : adj[u]) if (!vis[v] && sz[v] > sz[big_Child])
        big_Child = v;
    if (big_Child == 0) return;

    dfs(big_Child, u, 1);

    for (int v : adj[u]) if (!vis[v] && v != big_Child)
        dfs(v, u, 0);
}

void build_seg(int l, int r, int pos)
{
    if (l == r)
    {
        seg[pos] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_seg(l, mid, pos << 1);
    build_seg(mid + 1, r, (pos << 1) + 1);
    seg[pos] = seg[pos << 1] + seg[(pos << 1) + 1];
}

void update(int l, int r, int x, int val, int pos)
{
    if (r < x || x < l) return;
    if (l == r)
    {
        seg[pos] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, x, val, pos << 1);
    update(mid + 1, r, x, val, (pos << 1) + 1);
    seg[pos] = seg[pos << 1] + seg[(pos << 1) + 1];
}

int get(int l, int r, int L, int R, int pos)
{
    if (r < L || R < l) return 0;
    if (L <= l && r <= R)
    {
        return seg[pos];
    }

    int mid = (l + r) >> 1;
    return (get(l, mid, L, R, pos << 1) + get(mid + 1, r, L, R, (pos << 1) + 1));
}

int get_ans(int u, int v)
{
    int x = lca(u, v), res = 0;
    while(Head[u] != Head[x])
    {
        res += get(1, n, pos[head[Head[u]]], pos[u], 1);
        u = pa[0][head[Head[u]]];
    } res += get(1, n, min(pos[u], pos[x]), max(pos[u], pos[x]), 1);

    while(Head[v] != Head[x])
    {
        res += get(1, n, pos[head[Head[v]]], pos[v], 1);
        v = pa[0][head[Head[v]]];
    } res += get(1, n, min(pos[v], pos[x]), max(pos[v], pos[x]), 1);
    res -= a[x];
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n; string s; int x, y;
    REP(i, 1, n) scanf("%d", &a[i]);
    cin >> q; memset(ra, -1, sizeof(ra));
    REP(i, 1, q)
    {
        cin >> s; scanf("%d%d", &Q[i].Y.X, &Q[i].Y.Y);
        if (s == one)
        {
            Q[i].X = 1;
            x = findd(Q[i].Y.X); y = findd(Q[i].Y.Y);
            if (x != y)
            {
                uni(x, y);
                adj[Q[i].Y.X].pb(Q[i].Y.Y);
                adj[Q[i].Y.Y].pb(Q[i].Y.X);
            }
        }
        ef (s == two) Q[i].X = 2;
        else Q[i].X = 3;
    }

    // build dữ liệu cho truy vấn lca và hld :
    REP(i, 1, n) if (!vis[i]) dfs1(i, 0);
    memset(vis, 0, sizeof(vis));
    REP(i, 1, n) if (!vis[i]) dfs(i, 0, 0);
    while((1 << log2n) <= n) ++log2n; --log2n;
    REP(j, 1, log2n) REP(i, 1, n) pa[j][i] = pa[j - 1][pa[j - 1][i]];
    build_seg(1, n, 1);
    memset(ra, -1, sizeof(ra)); ed[0] = INF;

    // thuật toán chính :
    REP(i, 1, q)
    {
        if (Q[i].X == 1)
        {
            x = findd(Q[i].Y.X); y = findd(Q[i].Y.Y);
            if (x != y)
            {
                printf("yes\n");
                uni(x, y);
            } else printf("no\n");
        }
        ef (Q[i].X == 2)
        {
            update(1, n, pos[Q[i].Y.X], Q[i].Y.Y - a[Q[i].Y.X], 1);
            a[Q[i].Y.X] = Q[i].Y.Y;
        }
        else
        {
            x = findd(Q[i].Y.X); y = findd(Q[i].Y.Y);
            if (x == y)
            {
                printf("%d\n", get_ans(Q[i].Y.X, Q[i].Y.Y));
            } else printf("impossible\n");
        }
    }
}
