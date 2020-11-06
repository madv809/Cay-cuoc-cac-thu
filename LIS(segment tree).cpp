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
int it[4*30001], res[30001], n;
pair <int, int> a[30001];

int get (int L, int R, int l, int r, int k)
{
    if (R < l || L > r) return 0;
    if (L <= l && r <= R) return it[k];

    int mid = (l + r)>>1;
    return max(get(L, R, l, mid, 2*k), get(L, R, mid + 1, r, 2*k + 1));
}

void up (int l, int r, int kk, int val, int k)
{
    if (kk < l || r < kk) return;
    if (l == r)
    {
        it[k] = max(it[k], val);
        return;
    }

    int mid = (l + r)>>1;
    up(l, mid, kk, val, 2*k);
    up(mid + 1, r, kk, val, 2*k + 1);
    it[k] = max(it[2*k], it[2*k + 1]);
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
    int k;
    sort(a + 1, a + n + 1);
    res[a[1].Y] = k = 1;
    REP(i, 2, n)
    {
        if (a[i].X != a[i - 1].X) ++k;
        res[a[i].Y] = k;
    }

    up(1, k, res[1], 1, 1);
    int best = 1;
    REP(i, 2, n)
    {
        int x = 1 + get(1, res[i] - 1, 1, k, 1);
        best = max(best, x);
        up(1, k, res[i], x, 1);
    }

    printf("%d", best);
}
