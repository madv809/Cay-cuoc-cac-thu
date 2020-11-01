#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;
int a[101][101], trace[101], n, m;
double d[101];

bool check (int u, int v)
{
    while (u != 1 && u != v) u = trace[u];
    return (u == v);
}

bool BF (double r)
{
    REP(i, 1, n) d[i] = 1e7;
    d[1] = 0;
    memset(trace, 0, sizeof(trace));

    while (1)
    {
        bool stop = 1;
        REP(u, 1, n)
            REP(v, 1, n) if (a[u][v] && d[v] > d[u] + a[u][v] - r)
            {
                if (check(u, v)) return 1;
                d[v] = d[u] + a[u][v] - r;
                stop = 0;
                trace[v] = u;
            }

        if (stop) return 0;
    }
    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v, c;
    REP(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &c);
        if (a[u][v] > 0) a[u][v] = c;// = a[v][u] = c;
        else a[u][v] = min(a[u][v], c);//a[v][u] = min(a[u][v], c);
    }

    double l = 0, r = 1e7, mid;

    while (r - l > 0.01)
    {
        mid = (l + r)/2;
        if (BF(mid)) r = mid;// - 0.01;
        else l = mid;
    }
    if (l > 1e7 - 3) printf("-1");
    else cout << setprecision(2) << fixed << l;
}
