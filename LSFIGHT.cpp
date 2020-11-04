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
int n;
bool f[501][501], a[501][501];
vector <int> res;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n)
        REP(j, 1, n) cin >> a[i][j];
    FOR(i, 1, n) f[i][i + 1] = 1;
    f[n][1] = 1;

    for (int x = 2; x <= n - 1; ++x)
        for (int i = 1; i <= n; ++i)
        {
            int j = (i + x - 1)%n + 1;

            if (i < j)
            {
                for (int k = i + 1; k < j; ++k) if (f[i][k] && f[k][j] && (a[i][k] || a[j][k]))
                {
                    f[i][j] = 1;
                    break;
                }
            }
            else
            {
                for (int k = i + 1; k <= n; ++k) if (f[i][k] && f[k][j] && (a[i][k] || a[j][k]))
                {
                    f[i][j] = 1;
                    break;
                }
                if (f[i][j] == 0)
                    for (int k = 1; k < j; ++k) if (f[i][k] && f[k][j] && (a[i][k] || a[j][k]))
                    {
                        f[i][j] = 1;
                        break;
                    }
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) if (i != j)
                if (f[i][j] && f[j][i] && a[i][j])
                {
                    res.push_back(i);
                    break;
                }
        }

    cout << res.size() << endl;
    for (int v : res) printf("%d\n", v);
}
