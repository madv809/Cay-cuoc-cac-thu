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
int a[201][201], d[201], n, k;
bool vist[201];

void dfs (int u, int V, int k)
{
    vist[u] = 1;
    REP(v, 1, n) if (!vist[v] && a[u][v] < V)
    {
        d[v] = k;
        dfs(v, V, k);
    }
}

int can (int V)
{
    memset(vist, 0, sizeof(vist));
    int k = 0;
    REP(i, 1, n) if (!vist[i])
    {
        ++k;
        vist[i] = 1;
        d[i] = k;
        dfs(i, V, k);
    }
    return k;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);

    REP(i, 1, n) REP(j, 1, n) scanf("%d", &a[i][j]);

    int l = 0, r = 1e9, mid, x;
    while (l < r)
    {
        mid = (l + r + 1)/2;
        x = can(mid);
        if (x == k) l = mid;
        else if (x < k) r = mid - 1;
        else l = mid;
    }

    printf("%d", l);
}
