#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define ii pair<int, int>
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
int bit[300001], res[300001], n;
pair < ii , int > a[300001];

void update (int x)
{
    while (x <= 300000)
    {
        ++bit[x];
        x += x&(-x);
    }
}

int get (int x)
{
    int res = 0;
    while (x)
    {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

bool cmp (pair< ii, int> a, pair< ii, int> b)
{
    if (a.X.X != b.X.X) return (a.X.X < b.X.X);
    return (a.X.Y < b.X.Y);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) {scanf("%d%d", &a[i].X.X, &a[i].X.Y); a[i].Y = i;}
    sort(a + 1, a + n + 1, cmp);
    update(a[1].X.Y);

    int k = 1;
    REP(i, 2, n)
    {
        if (a[i].X.Y != a[i-1].X.Y || a[i].X.X != a[i-1].X.X) k = 0;
        ++k;
        update(a[i].X.Y);
        res[a[i].Y] = get(a[i].X.Y) - k;
    }

    REP(i, 1, n) printf("%d\n", res[i]);
}
