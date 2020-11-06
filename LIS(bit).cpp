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
int bit[30001], res[30001], k, n;
pair <int, int> a[30001];

int get (int k)
{
    int res = 0;
    while (k > 0)
    {
        res = max(res, bit[k]);
        k -= k&(-k);
    }
    return res;
}

void up (int kk, int val)
{
    while (kk <= k)
    {
        bit[kk] = max(bit[kk], val);
        kk += kk&(-kk);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &a[i].X);
        a[i].Y = i;
    }

    sort(a + 1, a + n + 1);
    res[a[1].Y] = k = 1;
    REP(i, 2, n)
    {
        if (a[i].X != a[i - 1].X) ++k;
        res[a[i].Y] = k;
    }

    up(res[1], 1);
    int best = 1;
    REP(i, 2, n)
    {
        int x = 1 + get(res[i] - 1);
        best = max(best, x);
        up(res[i], x);
    }

    printf("%d", best);
}
