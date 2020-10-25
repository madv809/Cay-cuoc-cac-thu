#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;
const LL INF = 99999999999999;
bool vist[501];
int aa[501], n, m;
vector <int> a[501];
LL d[501], c[501][501], t[501][501], mid;

bool Solve(int u, LL time, LL cost)
{
    if (u == n) return 1;
    vist[u] = 1;
    if (aa[u]) cost = mid;
    for (int v : a[u]) if (!vist[v] && cost >= c[u][v] && time + t[u][v] + d[v] == d[1])
        if (Solve(v, time + t[u][v], cost - c[u][v]))
            return 1;
    vist[u] = 0;
    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &aa[i]);
    scanf("%d", &m);
    int u, v;
    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        scanf("%lli%lli", &t[u][v], &c[u][v]);
        t[v][u] = t[u][v];
        c[v][u] = c[u][v];
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i, 0, n) d[i] = INF;
    d[n] = 0;
    while(1)
    {
        int maxx = 0;
        FOR(i, 1, n) if (!vist[i] && d[maxx] > d[i]) maxx = i;
        if (maxx == 1 || maxx == 0) break;
        vist[maxx] = 1;
        for (int v : a[maxx]) if (!vist[v]) d[v] = min(d[v], d[maxx] + t[maxx][v]);
    }
    memset(vist, 0, sizeof(vist));
    LL l = 0, r = 10000*30000;
    while (l < r)
    {
        memset(vist, 0, sizeof(vist));
        mid = (l + r)/2;
        if (Solve(1, 0, mid)) r = mid;
        else l = mid + 1;
    }
    //cout << Solve(1, 0, 3);
    printf("%lli", r);
}
