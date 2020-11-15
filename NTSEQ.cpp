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
int a[100001], n;
pair <LL, int> tmp_a[100002];
piL bit[100002];

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
        else if (bit[x].X == res.X) (res.Y += bit[x].Y)%=MOD;
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
    REP(i, 2, n)
    {
        if (tmp_a[i].X != tmp_a[i - 1].X) ++k;
        a[tmp_a[i].Y] = k;
    }

    REP(i, 1, n)
    {
        piL u = get(a[i] - 1);
        piL v = {1 + u.X, max((LL)1, u.Y)};
        up(a[i], v);
    }
    piL v = get(n);
    printf("%lli", v.Y);
}
