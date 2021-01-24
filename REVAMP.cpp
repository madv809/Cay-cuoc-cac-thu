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
const int mxn = 1e4 + 5;
const LL INF = 1e18;
priority_queue<pair<LL, pii>, vector<pair<LL, pii>>, greater<pair<LL, pii>>> h;
vector<int> a[mxn], c[mxn];
LL dp[mxn][25];
int n, m, k;
bool vis[mxn][25];
 
void add (const int &u, const int &v, const int &t1, const int &t2, const LL &w1, const LL &w2)
{
    if (t2 > k) return;
    if (dp[v][t2] > w1 + w2)
    {
        dp[v][t2] = w1 + w2;
        h.push({w1 + w2, {v, t2}});
    }
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m >> k;
    REP(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u].pb(v); a[v].pb(u);
        c[u].pb(w); c[v].pb(w);
    }
    REP(i, 2, n) REP(j, 0, k) dp[i][j] = INF;
    h.push({0, {1, 0}});
 
    while (h.size())
    {
        pair<LL, pii> x = h.top(); h.pop();
        LL w = x.X;
        int u = x.Y.X, t = x.Y.Y;
        if (dp[u][t] != w || vis[u][t]) continue;
        vis[u][t] = 1;
 
        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            add(u, v, t, t, w, (LL)c[u][i]);
            add(u, v, t, t + 1, w, 0);
        }
    }
    LL res = INF;
    REP(i, 1, k) res = min(res, dp[n][i]);
    cout << res;
}
 
