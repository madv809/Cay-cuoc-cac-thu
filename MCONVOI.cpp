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
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>

using namespace std;
const LL MOD = 1e9 + 7;
int a[300002], n;
piL bit[300002], f[300002];
pair <pLL, int> tmp_a[300002];
LL aa[300002];

void up (int x, piL u)
{
    while (x <= n)
    {
        if (bit[x].X < u.X) bit[x] = u;
        else if (bit[x].X == u.X) (bit[x].Y += u.Y)%=MOD;
        x += x&(-x);
    }
}

piL get (int x)
{
    piL res = {0, 0};
    while (x)
    {
        if (res.X < bit[x].X) res = bit[x];
        else if (res.X == bit[x].X) (res.Y += bit[x].Y)%=MOD;
        x -= x&(-x);
    }
    return res;
}

bool cmp_x (pair<pLL, int> a, pair<pLL, int> b)
{
    return (a.X.X < b.X.X);
}

bool cmp_y (pair<pLL, int> a, pair<pLL, int> b)
{
    return (a.X.Y < b.X.Y);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%lli%lli", &tmp_a[i].X.X, &tmp_a[i].X.Y);
    sort(tmp_a + 1, tmp_a + n + 1, cmp_x);
    //REP(i, 1, n) cout << tmp_a[i].X.X << ' '; cout << endl;
    REP(i, 1, n) {tmp_a[i].Y = i; aa[i] = tmp_a[i].X.X;}
    sort(tmp_a + 1, tmp_a + n + 1, cmp_y);

    int k = 1; a[tmp_a[1].Y] = 1;
    REP(i, 2, n)
    {
        if (tmp_a[i].X.Y != tmp_a[i - 1].X.Y) ++k;
        a[tmp_a[i].Y] = k;
    }

    k = 1; piL u, v;
    REP(i, 1, n)
    {
        while (aa[k] < aa[i]) {up(a[k], f[k]); ++k;};
        u = get(a[i] - 1);
        f[i] = {1 + u.X, max((LL)1, u.Y)};
    }
    while (k <= n) {up(a[k], f[k]); ++k;};
    v = get(n);
    //REP(i, 1, n) cout << bit[i].X << ' ' << bit[i].Y << endl;
    //REP(i, 1, n) cout << aa[i] << ' '; cout << endl;
    //REP(i, 1, n) cout << a[i] << ' '; cout << endl;
    printf("%d\n%lli", v.X, v.Y);
}
