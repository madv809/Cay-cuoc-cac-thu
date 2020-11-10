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
int bit[100001], n;
struct ed
{
    int a, b, c;
} a[100001];

void update (int x, int val)
{
    while (x <= n)
    {
        bit[x] = min(bit[x], val);
        x += x&(-x);
    }
}

int get (int x)
{
    int res = n + 1;
    while (x)
    {
        res = min(res, bit[x]);
        x -= x&(-x);
    }
    return res;
}

bool cmp (ed a, ed b)
{
    return (a.a < b.a);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int x;
    REP(i, 1, n) {scanf("%d", &x); a[x].a=i;}
    REP(i, 1, n) {scanf("%d", &x); a[x].b=i;}
    REP(i, 1, n) {scanf("%d", &x); a[x].c=i;}
    sort(a + 1, a + n + 1, cmp);
    REP(i, 1 , n) bit[i] = n + 1;

    int res = 0;
    REP(i, 1, n)
    {
        if (get(a[i].b) > a[i].c) ++res;
        update(a[i].b, a[i].c);
    }

    printf("%d", res);
}
