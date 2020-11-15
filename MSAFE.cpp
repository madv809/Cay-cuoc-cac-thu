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
int n;
LL T[100001], V[100001], a[100001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%lli", &a[i]);
    sort(a + 1, a + n + 1);
    int k = 1; LL c1 = 0, c2 = 0, sum1 = 0, sum2 = 0;
    LL range = 10000000/2;
    REP(i, 1, n)
    {
        ++c1; sum1 += a[i];
        while (a[i] - a[k] > range)
        {
            --c1; ++c2;
            sum1 -= a[k];
            sum2 += a[k++];
        }
        T[i] = c1*a[i] - sum1 + (c2 != 0)*(sum2 + c2*10000000 - c2*a[i]);
    }

    k = n; sum1 = sum2 = c1 = c2 = 0;
    for (int i = n; i >= 1; --i)
    {
        ++c1; sum1 += a[i];
        while (a[k] - a[i] > range)
        {
            --c1; ++c2;
            sum1 -= a[k];
            sum2 += a[k--];
        }
        V[i] = sum1 - c1*a[i] + (c2 != 0)*(c2*10000000 - sum2 + c2*a[i]);
    }
    LL res = 9999999999999;
    REP(i, 1, n) res = min(res, T[i] + V[i]);
    //REP(i, 1, n) cout << T[i] << ' '; cout << endl;
    //REP(i, 1, n) cout << V[i] << ' '; cout << endl;
    printf("%lli", res);
}
