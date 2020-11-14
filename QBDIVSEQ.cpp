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
int bit[100001], a[100001], f[100001], n;
pair <LL, int> tmp_a[100001];

void up (int x, int val)
{
    while (x <= n)
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
    scanf("%d", &n);
    REP(i, 1, n) {scanf("%lli", &tmp_a[i].X); tmp_a[i].Y = i;}
    sort(tmp_a + 1, tmp_a + n + 1);
    int k = 1; a[tmp_a[1].Y] = 1;

    REP(i , 2, n)
    {
        if (tmp_a[i].X != tmp_a[i - 1].X) ++k;
        a[tmp_a[i].Y] = k;
    }

    int res = 0;
    for (int i = n; i >= 1; --i)
    {
        f[i] = 1 + get(a[i] - 1);
        up(a[i], f[i]);
        res = max(res, f[i]);
    }
    printf("%d", res);
}
