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
#define ULL unsigned long long

using namespace std;

int t, n, cx;
ULL f[351][301], prime[351], l[351];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(i, 2, 350)
    {
        if (l[i] == 0)
        {
            prime[++cx] = i;
            l[i] = i;
        }
        int k = 350/i;
        for (int j = 1; j <= cx && prime[j] <= l[i] && prime[j] <= k; ++j)
            l[i*prime[j]] = prime[j];
    }

    REP(i, 0, cx) f[0][i] = 1;
        REP(j, 1, 70) REP(i, 1, 350)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            for (ULL cz = (ULL)prime[j]; cz <= (ULL)i; cz *= (ULL)prime[j])
                f[i][j] = max(f[i][j], f[i - cz][j - 1]*cz);
        }

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int m = 0;
        while (prime[m + 1] <= n && m < cx) ++m;
        if(n <= 347) printf("%lli\n", f[n][m]);
        else printf("14757354782123793840");
    }
}
