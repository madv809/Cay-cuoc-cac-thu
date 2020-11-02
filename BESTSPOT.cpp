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
int d[501], q[501], P, n, C;
bool inqueue[501], F[501];
vector <int> a[501], c[501];

void go (int s)
{
    memset(inqueue, 0, sizeof(inqueue));
    REP(i, 1, P) d[i] = 999999999;
    d[s] = 0;

    int x = 0, y = 0, u;
    q[0] = s;

    while (x != (y + 1)%P)
    {
        u = q[x];
        x = (x + 1)%P;
        inqueue[u] = 0;

        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            if (d[v] > d[u] + c[u][i])
            {
                d[v] = d[u] + c[u][i];
                if (!inqueue[v])
                {
                    y = (y + 1)%P;
                    q[y] = v;
                    inqueue[v] = 1;
                }
            }
        }
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &P, &n, &C);
    int u, v, w;
    REP(i, 1, n)
    {
        scanf("%d", &u);
        F[u] = 1;
    }
    REP(i, 1, C)
    {
        scanf("%d%d%d", &u, &v, &w);
        a[u].push_back(v);
        a[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }

    int minx = 999999999, x = 0;
    REP(i, 1, P)
    {
        go(i);
        int sum = 0;
        REP(j, 1, P) if (F[j])
            sum += d[j];
        if (sum < minx)
        {
            minx = sum;
            x = i;
        }
    }

    //REP(i, 1, C) if (!F[i]) cout << i << ' ';
    printf("%d", x);
}
