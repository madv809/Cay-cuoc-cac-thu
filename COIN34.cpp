#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second

using namespace std;
int t, best, c;
LL a[35], XX;
pair <LL, int> res[(1 << 18)];

int findd (LL tmp)
{
    int l = 0, r = c, mid;
    while (l < r)
    {
        mid = (l + r)>>1;
        if (res[mid].X == tmp) return mid;
        else if (res[mid].X > tmp) r = mid - 1;
        else l = mid + 1;
    }
    if (res[l].X == tmp) return l;
    return -1;
}

void up(int x, int cbit)
{
    if (x == -1) return;
    if (cbit + res[x].Y > best)
        best = cbit + res[x].Y;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    a[0] = 2; a[1] = 3; a[2] = 5;
    FOR(i, 3, 34) a[i] = a[i - 1] + a[i - 2] + a[i - 3];

    int n1 = 17;
    int n2 = 17;

    for (int i = 0; i < (1 << n1); ++i)
    {
        LL sum = 0; int cbit = 0;
        for (int j = 0; j < n1; ++j)
            if (i&(1 << j))
            {
                sum += a[j];
                ++cbit;
            }

        res[++c].X = sum;
        res[c].Y = cbit;
    }
    sort(res, res + c);
    int c1 = c; c = 0;
    FOR(i, 1, c1)
    {
        if (res[i].X != res[i - 1].X)
            res[++c] = res[i];
        else res[c].Y = max(res[c].Y, res[i].Y);
    }

    scanf("%d", &t);
    REP(k, 1, t)
    {
        scanf("%lli", &XX);
        best = -1;
        for (int i = 0; i < (1 << n2); ++i)
        {
            LL sum = 0; int cbit = 0;
            for (int j = 0; j < n2; ++j)
            if (i&(1 << j))
            {
                sum += a[j + n1];
                ++cbit;
            }

            int x = findd(XX - sum);
            up(x, cbit);
        }

        printf("Case #%d: %d\n", k, best);
    }
}
