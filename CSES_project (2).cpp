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
#define ef else if

using namespace std;
const int mxn = 5e2 + 5;
const int X[4] = { -1, 1, 0, 0};
const int Y[4] = { 0, 0, -1, 1 };
const int MOD = 1e9 + 7;
const int BASE = 10000;
int a[mxn][mxn], g[mxn][mxn], tmp_x1[mxn], tmp_x2[mxn], tmp_x3[mxn], tmp_x4[mxn], INF, t, n, m;
bool vis[mxn][mxn];
vector<pii> gg;
char ch[mxn][mxn];

bool can (int x)
{
    if (g[gg[0].X][gg[0].Y] < x || g[gg[1].X][gg[1].Y] < x) return 0;
    deque<pii> q;
    q.push_back({gg[0].X, gg[0].Y});
    memset(vis, 0, sizeof(vis));
    vis[gg[0].X][gg[0].Y] = 1;

    while (q.size())
    {
        int u = q.front().X, v = q.front().Y;
        q.pop_front();
        REP(k, 0, 3)
        {
            int i = u + X[k], j = v + Y[k];
            if (a[i][j] >= 0 && !vis[i][j] && g[i][j] >= x)
            {
                if (a[i][j] == INF) return 1;
                q.push_back({i, j});
                vis[i][j] = 1;
            }
        }
    }
    return 0;
}

void read()
{
    cin >> n >> m;
    INF = 100000000;
    REP(i, 1, n) REP(j, 1, m)
    {
        char x;
        cin >> x;
        ch[i][j] = x;
        if (x == '#') a[i][j] = -1;
        else if (x == '*')
        {
            ++t;
            a[i][j] = -2;
        }
        else if (x == 'S' || x == 'E')
        {
            a[i][j] = INF;
            gg.push_back({i, j});
        }
    }
    REP(i, 1, n) a[i][0] = a[i][m + 1] = -1;
    REP(i, 1, m) a[0][i] = a[n + 1][i] = -1;
    REP(j, 1, m)
    {
        tmp_x3[j] = tmp_x4[j] = INF;
        tmp_x1[j] = tmp_x2[j] = -INF;
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    read();

    REP(i, 1, n) REP(j, 1, m)
    {
        if (ch[i][j] == '*') tmp_x1[j] = i;
        int xx = INF;
        for (int k = j; k >= 1; --k) xx = min(xx, max(j - k, i - tmp_x1[k]));
        g[i][j] = xx;
    }

    for (int i = n; i >= 1; --i) REP(j, 1, m)
    {
        if (ch[i][j] == '*') tmp_x3[j] = i;
        for (int k = j; k >= 1; --k) g[i][j] = min(g[i][j], max(j - k, tmp_x3[k] - i));
    }

    REP(i, 1, n) for (int j = m; j >= 1; --j)
    {
        if (ch[i][j] == '*') tmp_x2[j] = i;
        for (int k = j; k <= m; ++k) g[i][j] = min(g[i][j], max(k - j, i - tmp_x2[k]));
    }

    for (int i = n; i >= 1; --i) for (int j = m; j >= 1; --j)
    {
        if (ch[i][j] == '*') tmp_x4[j] = i;
        for (int k = j; k <= m; ++k) g[i][j] = min(g[i][j], max(k - j, tmp_x4[k] - i));
    }

    if (!can(0))
    {
        cout << -1;
        return 0;
    }
    if (t == 0) { cout << "safe"; return 0; }

    int l = 0, r = n*m + 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (can(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
     n = m = 500;
    cout << n << ' ' << m << endl;
    REP(i, 1, n)
    {
        REP(j, 1, m) cout << '.';
        cout << endl;
    }
}
