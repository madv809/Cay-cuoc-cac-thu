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
int bit[10001], f[10001], n;
ii a[10001];

void up (int x, int val)
{
    while (x <= 10000)
    {
        bit[x] = max(bit[x], val);
        x += x&(-x);
    }
}

int get (int x)
{
    int res = 0;
    while (x)
    {
        res = max(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        REP(i, 1, n) scanf("%d%d", &a[i].X, &a[i].Y);
        sort(a + 1, a + n + 1);
        memset(bit, 0, sizeof(bit));
        int res = 1;
        for (int i = n; i >= 1; --i)
        {
            f[i] = 1 + get(a[i].Y - 1);
            up(a[i].Y, f[i]);
            res = max(res, f[i]);
        }
        printf("%d\n", res);
    }
}
