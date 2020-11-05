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

using namespace std;
int c, n;
LL res[(1 << 17)], cres[(1 << 17)], a1[50], a2[50], best = 999999999999, nres, sum;

int findd (LL tmp)
{
    int l = 1, r = c, mid;

    while (l < r)
    {
        mid = (l + r)>>1;
        if (sum - 2*(tmp + res[mid]) <= 0) r = mid;
        else l = mid + 1;
    }

    return l;
}

void up (int x, LL tmp)
{
    if (x <= 0) return;
    LL xx = abs(sum - 2*(tmp + res[x]));
    if (best > xx)
    {
        best = xx;
        nres = cres[x];
    }
    else if (best == xx) nres += cres[x];
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int n1 = n/2;
    int n2 = n - n1;
    FOR(i, 0, n1) {scanf("%lli", &a1[i]); sum += a1[i];}
    FOR(i, 0, n2) {scanf("%lli", &a2[i]); sum += a2[i];}

    for (int i = 0; i < (1 << n1); ++i)
    {
        LL tmp = 0;
        for (int j = 0; j < n1; ++j)
            if (i&(1 << j)) tmp += a1[j];
        res[++c] = tmp;
    }

    sort(res + 1, res + c + 1);
    int c1 = c;
    c = 1; cres[1] = 1;
    for (int i = 2; i <= c1; ++i)
    {
        if (res[i] != res[i - 1])
        {
            res[++c] = res[i];
            cres[c] = 1;
        }
        else if (res[i] == res[i - 1]) ++cres[c];
    }

    for (int i = 0; i < (1 << n2); ++i)
    {
        LL tmp = 0;
        for (int j = 0; j < n2; ++j)
            if (i&(1 << j)) tmp += a2[j];

        int x = findd(tmp);
        up(x, tmp);
        up(x - 1, tmp);
    }

    printf("%lli %lli", best, nres/2);
}
