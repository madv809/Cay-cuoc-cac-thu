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

long C[33][33];
int a[33];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(i, 0, 32) C[0][i] = 1;
    REP(i, 1, 32) REP(j, 1, i) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    int cz, x, n, k; LL xx, res;
    while ((cin >> n >> k))
    {
        cz = x = 0; res = 0;
        while (n)
        {
            a[++x] = n&1;
            n >>= 1;
        }

        for (int i = x - 1; i >= 1; --i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                xx = C[j][i - 1];
                res += xx*(1 + (j - 1)/k);
            }
        }

        for (int i = x - 1; i >= 1; --i)
        {
            if (a[i]) for (int j = i - 1; j >= 0; --j) res += C[j][i - 1]*(1 + (cz + j)/k);
            else ++cz;
        }
        res += 1*(cz != 0) + (cz!=0)*(cz - 1)/k;
        cout << res << endl;
    }
}
