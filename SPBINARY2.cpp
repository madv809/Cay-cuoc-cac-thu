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

const LL MOD = 1e9;
LL f[1000001][2], n, k;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%lli%lli", &n, &k);
    f[0][1] = 1; f[1][0] = 1; f[0][0] = 1; f[1][1] = 1;
    for (LL i = 2; i <= k; ++i)
    {
        f[i][0] = (f[i - 1][0] + f[i - 1][1])%MOD;
        f[i][1] = (f[i - 1][1] + f[i - 1][0])%MOD;
    }

    for (LL i = k + 1; i <= n; ++i)
    {
        f[i][0] = (f[i - 1][0] + f[i - 1][1] - f[i - k - 1][1])%MOD;
        if (f[i][0] < 0) f[i][0] += MOD;
        f[i][1] = (f[i - 1][1] + f[i - 1][0] - f[i - k - 1][0])%MOD;
        if (f[i][1] < 0) f[i][1] += MOD;
    }

    cout << ((f[n][0] + f[n][1])%MOD);
}
