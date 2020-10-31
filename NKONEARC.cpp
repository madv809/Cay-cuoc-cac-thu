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
int degP[2001], degS[2001], m, n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v;
    REP(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        degP[u] += 1;
        degS[v] += 1;
    }

    int  deg1P = 0, deg1S = 0;
    REP(i, 1, n)
    {
        if (degS[i] == 0 && degP[i] >= 1) ++deg1P;
        if (degP[i] == 0 && degS[i] >= 1) ++deg1S;
    }

    if (deg1P == deg1S && deg1S == 1)
    {
        printf("YES\n");

        REP(i, 1, n) if (degP[i] == 0 && degS[i] >= 1)
            {
                printf("%d ", i);
                break;
            }

        REP(i, 1, n) if (degS[i] == 0 && degP[i] >= 1)
            {
                printf("%d ", i);
                break;
            }
    }
    else if (deg1S == 1)
    {
        printf("YES\n");
        REP(i, 1, n) if (degP[i] == 0 && degS[i] >= 1)
        {
            printf("%d ", i);
            if (i != n) printf("%d", i + 1);
            else printf("%d", i - 1);
            break;
        }
    }
    else if (deg1P == 1)
    {
        printf("YES\n");
        REP(i, 1, n) if (degS[i] == 0 && degP[i] >= 1)
        {
            printf("%d ", i);
            if (i != n) printf("%d", i + 1);
            else printf("%d", i - 1);
            break;
        }
    }
    else printf("NO\n");
}
