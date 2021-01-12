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
const LL BASE = 311;
vector<int> a[mxn], pa;
int in_pa[mxn], vist[mxn], re[mxn], n, m, kara, s, t;
 
void BFS()
{
    queue<int> rose;
    rose.push(s); vist[s] = 1;
    bool ok = 0;
    while (rose.size())
    {
        int u = rose.front(); rose.pop();
        for (int v : a[u]) if (!vist[v])
        {
            re[v] = u;
            vist[v] = 1;
            rose.push(v);
            if (v == t) {ok = 1; break;}
        }
        if (ok) break;
    }
    if (ok)
    {
        pa.push_back(t);
        int x = t;
        do
        {
            x = re[x];
            pa.push_back(x);
        } while (x != s);
    }
    else pa.push_back(s);
    reverse(pa.begin(), pa.end());
    int x = pa.size();
    for (int i = 0; i < x; ++i) in_pa[pa[i]] = i + 1;
}
 
void dfs (int u)
{
    vist[u] = 2;
    for (int v : a[u]) if (vist[v] != 2)
    {
        if (in_pa[u] && in_pa[v]) continue;
        if (in_pa[v]) kara = max(kara, in_pa[v]);
        else dfs(v);
    }
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m >> s >> t;
    REP(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
    }
    BFS();
    int res = 0;
    if (pa.back() != t) {cout << "0"; return 0;}
    for (int u : pa)
    {
        if (u != s && u != t)
            res += (in_pa[u] >= kara);
        dfs(u);
    }
    cout << res;
}
