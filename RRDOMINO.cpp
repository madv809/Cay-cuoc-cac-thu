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
const int mxn = 2e3 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 5;
const int X[5] = { 0, -1, 1, 0, 0 };
const int Y[5] = { 0, 0, 0, -1, 1 };
struct node
{
    int val, node, color;
}a[mxn][mxn];
int d[mxn], f[mxn][mxn], c[mxn][mxn], cost[mxn][mxn], p[mxn], n, m, k, s0, s, t, x, color;
bool inq[mxn];
vector<int> g[mxn];

void build_graph()
{
    REP(i, s0, t) g[i].clear();
    REP(i, 1, n) REP(j, 1, m) if (a[i][j].color == 1)
    {
        int node1 = a[i][j].node;
        g[s].pb(node1);
        g[node1].pb(s);
        c[s][node1] = 1;
        c[node1][s] = f[s][node1] = f[node1][s] = cost[s][node1] = cost[node1][s] = 0;

        REP(x, 1, 4)
        {
            if (i + X[x] > n || i + X[x] < 1 || j + Y[x] > m || j + Y[x] < 1) continue;
            int node2 = a[i + X[x]][j + Y[x]].node;

            // cạnh giữa node1 và node2
            g[node1].pb(node2);
            g[node2].pb(node1);
            cost[node1][node2] = -a[i][j].val*a[i + X[x]][j + Y[x]].val;
            cost[node2][node1] = -cost[node1][node2];
            c[node1][node2] = 1;
            c[node2][node1] = f[node1][node2] = f[node2][node1] = 0;
        }
    }
    else
    {
        // cạnh nữa giữa node2 và t
        int node2 = a[i][j].node;
        g[node2].pb(t);
        g[t].pb(node2);
        c[node2][t] = 1;
        c[t][node2] = f[node2][t] = f[t][node2] = cost[node2][t] = cost[t][node2] = 0;
    }

    /*// tạo thêm k đỉnh ảo
    REP(i, 1, k)
    {
        ++x;
        g[s].pb(x);
        g[x].pb(s);
        c[s][x] = 1;
        c[x][s] = f[s][x] = f[x][s] = cost[s][x] = cost[x][s] = 0;

        g[x].pb(t);
        g[t].pb(x);
        c[x][t] = 1;
        c[t][x] = f[x][t] = f[t][x] = cost[x][t] = cost[t][x] = 0;
    }*/

    // đỉnh ảo s0 nối với s
    g[s0].pb(s);
    g[s].pb(s0);
    c[s0][s] = k;
    c[s][s0] = f[s][s0] = f[s0][s] = cost[s][s0] = cost[s0][s] = 0;
}

bool find_path(int s, int t)
{
    REP(i, s, t) { d[i] = INF; inq[i] = 0; }
    d[s] = 0;
    queue<int> q;
    q.push(s);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;

        for (int v : g[u]) if (c[u][v] > f[u][v] && d[v] > d[u] + cost[u][v])
        {
            d[v] = d[u] + cost[u][v];
            p[v] = u;

            if (!inq[v])
            {
                inq[v] = 1;
                q.push(v);
            }
        }
    }

    return (d[t] != INF);
}

void solve ()
{
    int res = 0;
    while (find_path(s0, t))
    {
        int ff = INF, cur = t;
        while (cur != s0)
        {
            ff = min(ff, c[p[cur]][cur] - f[p[cur]][cur]);
            cur = p[cur];
        }

        res += ff*d[t];
        cur = t;
        while (cur != s0)
        {
            f[p[cur]][cur] += ff;
            f[cur][p[cur]] -= ff;
            cur = p[cur];
        }
    }
    cout << (-res) << endl;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);

    while (cin >> n)
    {
        cin >> m >> k;
        x = 2; color = 0;
        s0 = 1; s = 2; t = n*m + 3;
        REP(i, 1, m)
        {
            cin >> a[1][i].val;
            a[1][i].node = ++x;
            a[1][i].color = (color ^= 1);
        }

        REP(i, 2, n) REP(j, 1, m)
        {
            cin >> a[i][j].val;
            a[i][j].node = ++x;
            a[i][j].color = (a[i - 1][j].color^1);
        }

        build_graph();
        solve();
    }
}
