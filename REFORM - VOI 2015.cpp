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
const int mxn = 2e5 + 5;
const LL INF = 1e18;
LL num[mxn], low[mxn], child[mxn], gr[5], n, t, tt, C1, C2, res;
int vis[mxn], m;
vector<int> a[mxn];
bool en[mxn];
 
void dfs1 (int p, int u)
{
    vis[u] = t;
    child[u] = 1;
    for (int v : a[u]) if (v != p && vis[v] != t)
    {
        dfs1(u, v);
        child[u] += child[v];
    }
}
 
void dfs2 (int p, int u)
{
    low[u] = num[u] = ++t;
 
    for (int v : a[u]) if (v != p)
    {
        bool ok = 0;
        if (num[v]) { low[u] = min(low[u], num[v]); ok = 1; }
        if (!ok)
        {
            dfs2(u, v);
            low[u] = min(low[u], low[v]);
        }
 
        if (low[v] >= num[v] && en[v])
        {
            if (tt == 1)
                res += child[v]*(n - child[v]) - 1;
        }
        else
        {
            if (!en[v]) continue;
            if (tt == 1)
                res += (n - 1)*n/2 - m;
            else res += C1*C2;
        }
    }
    en[u] = 1;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m;
    REP(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v); a[v].pb(u);
    }
 
    t = 1;
    REP(i, 1, n) if (vis[i] == 0)
    {
        ++t;
        if (t > 3) { cout << "0"; return 0; }
        dfs1(0, i);
    }
    tt = t - 1;
    if (tt == 2)
    {
        REP(i, 1, n) if (vis[i] == 2) ++C1;
        else ++C2;
    }
 
    REP(i, 1, n) if (!num[i])
        dfs2(0, i);
 
    cout << res;
}

/* Bài này nếu chỉ dfs bình thường thì sẽ đếm trùng các cạnh, ta dùng thêm một mảng en[u]
để cố định rằng chỉ xét cạnh mà ta đứng ở đỉnh cao hơn, tức là node v là con của u thì thoát ra khỏi v trước và en[v] = 1 */
 
