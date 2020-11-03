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
int q[30001], s[30001], n, m;
vector <int> a[30001];
vector <LL> c[30001];
LL d1[30001], d2[30001], f1[30001], f2[30001];
bool inq[30001];

void BF (LL d[], LL f[], int s)
{
    REP(i, 1, n) d[i] = 999999999;
    memset(inq, 0, sizeof(inq));

    q[0] = s;
    d[s] = 0;
    f[s] = 1;

    int x = 0, y = 0;

    while (x != (y + 1)%n)
    {
        int u = q[x];
        x = (x + 1)%n;
        inq[u] = 0;

        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];

            if (d[v] > d[u] + c[u][i])
            {
                d[v] = d[u] + c[u][i];
                f[v] = f[u];
                if (!inq[v])
                {
                    y = (y + 1)%n;
                    q[y] = v;
                    inq[v] = 1;
                }
            }
            else if (d[v] == d[u] + c[u][i])
                f[v] += f[u];
        }
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v; LL w;
    REP(i, 1, m)
    {
        scanf("%d%d%lli", &u, &v, &w);
        a[u].push_back(v);
        a[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }
    BF(d1, f1, 1);
    BF(d2, f2, n);

    int res = n - 2;
    FOR(i, 2, n) if (d1[i] + d2[i] == d1[n] && f1[i]*f2[i] == f1[n])
    {
        --res;
        s[i] = 1;
    }

    printf("%d\n", res);
    FOR(i, 2, n) if (!s[i]) printf("%d\n", i);
    /*REP(i, 1, n) cout << d1[i] << ' ';
    cout << endl;
    REP(i, 1, n) cout << d2[i] << ' ';
    cout << endl;
    REP(i, 1, n) cout << f1[i] << ' ';*/
}
