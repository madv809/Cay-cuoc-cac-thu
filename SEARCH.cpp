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
int c[100001], f[100001], n, m, p, count_a;
bool a[100001], b[100001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &m, &n, &p);
    int x;
    REP(i, 1, m)
    {
        scanf("%d", &x);
        if (!a[x]) ++count_a;
        a[x] = 1;
    }

    REP(i, 1, n)
    {
        scanf("%d", &x);
        b[x] = 1;
    }

    REP(i, 1, p) scanf("%d", &c[i]);

    int k = 1, res = 0, l = 0, countt=0;
    REP(i, 1, p)
    {
        int x = c[i];
        if (b[x])
        {
            l = countt = 0;
            ++k;
            continue;
        }
        if (a[x] && f[x] != k)
        {
            ++countt;
            f[x] = k;
        }
        ++l;
        if (countt == count_a) res = max(res, l);
    }
    printf("%d", res);
}
