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
int a[18], n, x;
LL dp[33][17];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= 2*n + 1; ++i) scanf("%d", &a[i]);
    scanf("%d", &x);

    int last = 2*n + 1, k = 0;
    dp[last][0] = 1;
    for (int i = last - 1; i >= n + 2; --i)
    {
        ++k;
        for (int j = k; j >= 0; --j)
        {
            dp[i][j] += dp[i + 1][j + 1];
            if (j != 0)
                dp[i][j] += dp[i + 1][j - 1];
        }
    }

    k = n + 1;
    for (int i = n + 1; i >= 1; --i)
    {
        --k;
        for (int j = k; j >= 0; --j)
        {
            dp[i][j] += dp[i + 1][j + 1];
            if (j != 0)
                dp[i][j] += dp[i + 1][j - 1];
        }
    }

    LL res = 0;
    int v = 0;
    for (int i = 2; i <= last; ++i)
    {
        LL X = 0;
        if (a[i - 1] != 0)
        {
            if (a[i] != a[i - 1] - 1)
                res += dp[i][a[i - 1] - 1];
        }
    }
    printf("%lli\n", res + 1);

    printf("0 ");
    int tmp = 0;
    for (int i = 2; i <= last; ++i)
    {
        if (tmp != 0)
        {
            if (x <= dp[i][tmp - 1])
            {
                tmp = tmp - 1;
                printf("%d ", tmp);
            }
            else
            {
                ++tmp;
                printf("%d ", tmp);
                x -= dp[i][tmp - 2];
            }
        }
        else
        {
            ++tmp;
            printf("%d ", tmp);
        }
    }
}
