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
int q[5001], n, m;
LL d[5001], f[5001];
vector <int> a[5001];
vector <LL> c[5001];
bool p[5001][5001], inqueue[5001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int k, u, v;
    LL l;
    REP(i, 1, m)
    {
        scanf("%d%d%d%lli", &k, &u, &v, &l);
        //if (p[u][v]) continue;
        a[u].push_back(v);
        c[u].push_back(l);
        if (k == 2)
        {
            a[v].push_back(u);
            c[v].push_back(l);
        }
        if (l < 0)
        {
            cout << "ok";
            return 0;
        }

        //p[u][v] = p[v][u] = 1;
    }

    REP(i, 1, n) d[i] = 9999999999;
    q[0] = 1;
    d[1] = 0;
    f[1] = 1;

    int x = 0, y = 0;

    while (x != (y + 1)%n)
    {
        int u = q[x];
        x = (x + 1)%n;
        inqueue[u] = 0;

        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            LL w = c[u][i];

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                f[v] = f[u];
                if (!inqueue[v])
                {
                    y = (y + 1)%n;
                    q[y] = v;
                    inqueue[v] = 1;
                }
            }
            else if (d[v] == d[u] + w) f[v] += f[u];
        }
    }

    cout << d[n] << ' ' << f[n];
}
