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
int bit[100001], f[100001], g[100001], n;
LL a[100001];
struct ed
{
    LL val;
    int t;
} tmp_a[100001];

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

bool cmp (ed a, ed b)
{
    return (a.val < b.val);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) {scanf("%lli", &a[i]); tmp_a[i].val = a[i]; tmp_a[i].t = i;}
    sort(tmp_a + 1, tmp_a + n + 1, cmp);
    int k = 1; a[tmp_a[1].t] = 1;
    REP(i, 2, n)
    {
        if (tmp_a[i].val != tmp_a[i - 1].val) ++k;
        a[tmp_a[i].t] = k;
    }

    REP(i, 1, n)
    {
        f[i] = 1 + get(a[i] - 1);
        up(a[i], f[i]);
    }
    memset(bit, 0, sizeof(bit));
    for (int i = n; i >= 1; --i)
    {
        g[i] = 1 + get(a[i] - 1);
        up(a[i], g[i]);
    }
    int res = 0;
    REP(i, 1, n) res = max(res, 2*min(f[i], g[i]) - 1);
    //REP(i, 1, n) cout << a[i] << ' '; cout << endl;
    //cout << f[5] << ' ' << g[5]; cout << endl;

    printf("%d", res);
}
