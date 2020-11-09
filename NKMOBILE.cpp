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
int bit[1025][1025], s, x;

int get1 (int x, int y)
{
    int y1, res = 0;
    while (x)
    {
        y1 = y;
        while (y1)
        {
            res += bit[x][y1];
            y1 -= y1&(-y1);
        }
        x -= x&(-x);
    }
    return res;
}

int get (int l, int b, int r, int t)
{
    return (get1(r, t) - get1(l - 1, t) + get1(l - 1, b - 1) - get1(r, b - 1));
}

void update (int x, int y, int val)
{
    int y1;
    while (x <= s)
    {
        y1 = y;
        while (y1 <= s)
        {
            bit[x][y1] += val;
            y1 += y1&(-y1);
        }
        x += x&(-x);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &x, &s);
    scanf("%d", &x);
    int u, v, l, b, r, t, c;
    ++s;
    while (x != 3)
    {
        if (x == 1)
        {
            scanf("%d%d%d", &u, &v, &c);
            update(u + 1, v + 1, c);
        }
        else
        {
            scanf("%d%d%d%d", &l, &b, &r, &t);
            printf("%d\n", get(l + 1, b + 1, r + 1, t + 1));
        }
        scanf("%d", &x);
    }
}
