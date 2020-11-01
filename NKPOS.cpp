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
#include <stack>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;
int a[201][201], st[2001], res[2001], m, n, c, k;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v;
    REP(i, 1, n) scanf("%d", &u);

    REP(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        a[u][v] += 1;
        a[v][u] += 1;
    }

    st[1] = k = 1;

    while (k > 0)
    {
        int u = st[k]; bool ok = 1;

        for (int v = 1; v <= n; ++v) if (a[u][v] > 0)
        {
            a[u][v] -= 1;
            a[v][u] -= 1;
            st[++k] = v;
            ok = 0;
            break;
        }

        if (ok)
        {
            res[++c] = u;
            --k;
        }
    }

    printf("%d\n", c - 1);
    for (int i = c; i >= 1; --i) printf("%d ", res[i]);
}
