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
int m, n;
LL f[50001], a[50001], b[50001], q[50001];
bool inqueue[50001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%lli", &a[i]);
    scanf("%d", &m);
    REP(i, 1, m) scanf("%lli", &b[i]);

    REP(i, 0, 49999) f[i] = 9999999999999;

    f[0] = 0;
    q[0] = 0;
    int x = 0, y = 0;

    while (x != (y + 1)%50000)
    {
        LL u = q[x];
        x = (x + 1)%50000;
        inqueue[u] = 1;

        REP(i, 1, n) if (f[(u + a[i])%a[1]] > f[u] + a[i])
        {
            f[(u + a[i])%a[1]] = f[u] + a[i];
            if (!inqueue[(u + a[i])%a[1]])
            {
                y = (y + 1)%50000;
                q[y] = (u + a[i])%a[1];
                inqueue[(u + a[i])%a[1]] = 1;
            }
        }
    }

    REP(i, 1, m) if (b[i] >= f[b[i]%a[1]]) printf("TAK\n");
    else printf("NIE\n");
}
