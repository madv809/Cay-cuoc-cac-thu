#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define ii pair<int, int>

using namespace std;
int d[100001], p;

int findd (int u)
{
    while (d[u] > 0) u = d[u];
    return u;
}

void uni (int x, int y)
{
    if (x == y) return;
    if (d[x] < d[y])
    {
        d[x] += d[y];
        d[y] = x;
    }
    else
    {
        d[y] += d[x];
        d[x] = y;
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &p);
    int u, v, k;
    memset(d, -1, sizeof(d));
    REP(i, 1, p)
    {
        scanf("%d%d%d", &u, &v, &k);
        if (k == 1) uni(findd(u), findd(v));
        else
            if (findd(u) != findd(v)) printf("0\n");
            else printf("1\n");
    }
}
