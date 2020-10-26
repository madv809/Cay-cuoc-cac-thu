#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
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
const LL INF = 1000000000000000009;
LL dp[100001][(1 << 5)], a[5][100001];
bool ok[100001][(1 << 5)];
int n;

bool valid (int state1, int state2)
{
    FOR(i, 0, 2) if (((1 << i)&state1) && ((1 << (i + 1))&state1)) return 0;
    FOR(i, 0, 2) if (((1 << i)&state2) && ((1 << (i + 1))&state2)) return 0;
    FOR(i, 0, 3) if (((1 << i)&state1) && ((1 << i)&state2)) return 0;
    return 1;
}

LL calc (int state, int k)
{
    LL res = 0;
    FOR(i, 0, 3) if (state&(1 << i))
        res += a[i + 1][k];
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    LL maxx = -INF;
    FOR(i, 1, 4)
        FOR(j, 1, n)
        {
            scanf("%lli", &a[i][j]);
            maxx = max(maxx, a[i][j]);
        }

    FOR(i, 1, n)
        for (int j = 0; j < (1 << 4) - 1; ++j) dp[i][j] = -INF;

    FOR(i, 0, (1 << 4) - 1) if (valid(i, 0))
    {
        dp[1][i] = calc(i, 1);
        ok[1][i] = (i != 0);
    }

    FOR(i, 2, n)
    {
        for (int j = 0; j < (1 << 4) - 1; ++j)
            for(int k = 0; k < (1 << 4) - 1; ++k) if (valid(j, k))
            {
                if (dp[i][j] < dp[i - 1][k] + calc(j, i))
                {
                    dp[i][j] = dp[i - 1][k] + calc(j, i);
                    ok[i][j] = (j || ok[i - 1][k]);
                }
            }
    }
    LL res = -INF;
    bool okk = 1;
    for (int i = 0; i < (1 << 4) - 1; ++i) if (res < dp[n][i])
    {
        res = dp[n][i];
        okk = ok[n][i];
    }
    if (okk) printf("%lli", res);
    else printf("%lli", maxx);
}
