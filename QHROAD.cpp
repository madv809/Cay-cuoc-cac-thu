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
const LL INF = 1e18;
pii a[mxn];
vector<int> res, qu;
int d[mxn], inv[mxn], n, m, q;
 
int findd (int u)
{
    if (d[u] < 0) return u;
    return d[u] = findd(d[u]);
}
 
void uni (int u, int v)
{
    --n;
    if (d[u] < d[v])
    {
        d[u] += d[v];
        d[v] = u;
    }
    else
    {
        d[v] += d[u];
        d[u] = v;
    }
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m >> q;
    REP(i, 1, m) cin >> a[i].X >> a[i].Y;
    REP(i, 1, q) { int x; cin >> x; inv[x] = 1; qu.pb(x); }
    memset(d, -1, sizeof(d));
    REP(i, 1, m) if (!inv[i] && findd(a[i].X) != findd(a[i].Y)) uni(findd(a[i].X), findd(a[i].Y));
    res.pb(n);
    reverse(qu.begin(), qu.end());
    for (int i = 0; i < qu.size(); ++i)
    {
        int u = a[qu[i]].X, v = a[qu[i]].Y;
        int x = findd(u), y = findd(v);
        if (x != y) uni(x, y);
        res.pb(n);
    }
    reverse(res.begin(), res.end());
    for (int i = 1; i < res.size(); ++i) cout << res[i] << endl;
}
 
