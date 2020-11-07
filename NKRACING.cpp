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
int d[100001], n, m;
LL sum;
struct ed
{
    int u, v;
    LL c;
} a[100001];

int findd (int u)
{
    while (d[u] > 0) u = d[u];
    return u;
}

void uni (int u, int v)
{
    if (d[u] < d[v])
    {
        d[u] += d[v];
        d[v] = u;
    }
    else
    {
        d[v] += d[u];
        d[u] = v;
    }
}

bool cmp (ed a, ed b)
{
    return (a.c > b.c);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, 1, m) {scanf("%d%d%lli", &a[i].u, &a[i].v, &a[i].c); sum += a[i].c;}

    sort(a + 1, a  + m + 1, cmp);
    memset(d, -1, sizeof(d));

    REP(i, 1, m)
    {
        int x = findd(a[i].u), y = findd(a[i].v);
        if (x != y)
        {
            uni(x, y);
            sum -= a[i].c;
        }
    }

    printf("%lli", sum);
}
