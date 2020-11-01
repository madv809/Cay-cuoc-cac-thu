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
int a[201][201], w[201][201], deg[201], st[20001], res[20001], oddV, n, m, k, c = -1;
bool vist[201];

int dfs (int u)
{
    vist[u] = 1;
    int x = 1;
    REP(v, 1, n) if (!vist[v] && a[u][v])
        x += dfs(v);

    return x;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v, x;
    REP(i, 1, m)
    {
        scanf("%d%d%d", &u, &v, &x);
        a[u][v] = 1;
        a[v][u] = 1;
        w[u][v] = x;
        w[v][u] = x;
        deg[u] += 1;
        deg[v] += 1;
    }

    if (dfs(1) != n)
    {
        printf("-1");
        return 0;
    }

    REP(i, 1, n) if (deg[i]&1) ++oddV;
    if (oddV)
    {
        printf("-1");
        return 0;
    }

    st[1] = k = 1;

    while (k > 0)
    {
        int u = st[k]; bool ok = 1;

        REP(v, 1, n) if (a[u][v] > 0)
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

    LL sum = 0;
    REP(i, 1, c) sum += w[res[i - 1]][res[i]];

    if (sum < 0) printf("-1");
    else
    {
        for (int i = 0; i <= c - 1; ++i)
        {
            sum = 0;
            int k = 2; bool ok = 1;
            for (int j = i + 1; k <= c; ++j)
            {
                int x = j%c;
                sum += w[res[(x - 1)+(x == 0)*c]][res[x]];
                if (sum < 0)
                {
                    ok = 0;
                    break;
                }
                ++k;
            }
            if (ok)
            {
                for (int j = i; j <= c - 1; ++j)
                    printf("%d ", res[j]);
                for (int j = 0; j <= i - 1; ++j)
                    printf("%d ", res[j]);
                printf("%d ", res[i]);
            }
        }
    }
}
