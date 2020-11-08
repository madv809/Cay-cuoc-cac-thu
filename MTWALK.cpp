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
int a[101][101], n;
bool vist[101][101];
const int xx[4] = {-1, 0, 1, 0}, yy[4] = {0, 1, 0, -1};

pair <int, int> notOver(pair<int, int> u, int i)
{
    if (u.X + xx[i] < 1 || u.X + xx[i] > n) return {0, 0};
    if (u.Y + yy[i] < 1 || u.Y + yy[i] > n) return {0, 0};
    return {u.X  + xx[i], u.Y + yy[i]};
}

bool can (int st, int en)
{
    queue< pair<int, int> > q;
    pair<int, int> u, v, x;
    memset(vist, 0, sizeof(vist));
    if (a[1][1] < st || a[1][1] > en) return 0;
    q.push({1, 1});
    vist[1][1] = 1;

    while (q.size())
    {
        u = q.front(); q.pop();
        REP(i, 0, 3)
        {
            v = notOver(u, i);
            if (v.X == 0) continue;
            if (a[v.X][v.Y] < st || a[v.X][v.Y] > en) continue;
            if (vist[v.X][v.Y]) continue;
            vist[v.X][v.Y] = 1;
            q.push({v.X, v.Y});
        }
    }
    if (vist[n][n]) return 1;
    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) REP(j, 1, n) scanf("%d", &a[i][j]);

    int l = 0, r = 110, mid;
    while (l < r)
    {
        bool ok = 1;
        mid = (l + r)>>1;
        for (int i = 0; i <= 110 - mid; ++i)
            if (can(i, i + mid))
            {
                r = mid;
                ok = 0;
                break;
            }
        if (ok) l = mid + 1;
    }

    printf("%d", l);
}
