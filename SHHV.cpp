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
LL f[14], a[14], p, x, sum, tmp;
bool b[14];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n = 0;
    while ((cin >> x)) a[++n] = x;
    f[n--] = 1;
    for (int i = n; i >= 1; --i) f[i] = (n-(LL)i+(LL)1)*f[i + 1];

    LL k = 0;
    REP(i, 1, n)
    {
        REP(j, 1, n) if (!b[j])
        {
            if (a[i] == j) {b[j] = 1; break;}
            else k += f[i + 1];
        }
    }
    //REP(i, 1, n) cout << f[i] << ' '; cout << endl;
    printf("%lli\n", k + 1);

    memset(b, 0, sizeof(b));
    k = a[n + 1];
    REP(i, 1, n)
    {
        REP(j, 1, n) if (!b[j])
        {
            if (f[i + 1] >= k) {printf("%d ", j); b[j] = 1; break;}
            else k -= f[i + 1];
        }
    }
}
