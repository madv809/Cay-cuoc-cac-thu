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
#include <queue>

using namespace std;
int bit[30001], dp[30001], res, n;
struct ti
{
    int st, en;
} a[30001];

int get (int x)
{
    int res = 0;
    while (x)
    {
        if (dp[res] < dp[bit[x]])
            res = bit[x];
        x -= (x&(-x));
    }
    return res;
}

void up (int x, int indx)
{
    while (x <= 3e4)
    {
        if (dp[bit[x]] < dp[indx])
            bit[x] = indx;
        x += (x&(-x));
    }
}

bool cmp (ti a, ti b)
{
    return (a.en < b.en);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d%d", &a[i].st, &a[i].en);
    sort(a + 1, a + n + 1, cmp);

    dp[1] = res = a[1].en - a[1].st;
    up(a[1].en, 1);

    REP(i, 2, n)
    {
        dp[i] = a[i].en - a[i].st + dp[get(a[i].st)];
        up(a[i].en, i);
        res = max(res, dp[i]);
    }

    printf("%d", res);
}
