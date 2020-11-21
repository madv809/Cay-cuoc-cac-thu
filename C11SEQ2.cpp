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
#define BigN LL

using namespace std;

int aa[63], n, k;
bool used[63];
BigN C[63][63], p;
pii a[63];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, 1, n) {scanf("%d", &a[i].X); a[i].Y = i;}
    REP(i, 0, n) C[0][i] = 1;

    REP(i, 1, n) REP(j, 1, i) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    //REP(i, 0, n) cout << C[0][i] << ' '; cout << endl;
    sort(a + 1, a + n + 1);
    cin >> p;

    //REP(i, 1, n) cout << a[i].X << ' ' << a[i].Y << endl;
    int kk = k - 1, nn = n - 1, cz = 0, cx = 0;
    while (1)
    {
        REP(i, 1, n) if (!used[i] && a[i].Y > cz)
        {
            cx = 0;
            for (int j = i + 1; j <= n; ++j) if (used[j] && a[j].Y > a[i].Y) ++cx;
            //int pp = p[0], po = C[kk][n - cx - a[i].Y][0];
            if (p > C[kk][n - cx - a[i].Y]) p = p - C[kk][n - cx - a[i].Y];
            else
            {
                printf("%d ", a[i].X);
                used[i] = 1;
                --kk;
                cz = a[i].Y;
                break;
            }
        }
        if (kk == -1) break;
    }
    printf("\n");

    REP(i, 1, k) scanf("%d", &aa[i]);
    BigN S; S = 1; kk = k - 1; cz = 0;
    memset(used, 0, sizeof(used));
    REP(i, 1, k)
    {
        REP(j, 1 ,n) if (!used[j] && a[j].Y > cz)
        {
            if (a[j].X == aa[i]) {--kk; cz = a[j].Y; used[j] = 1; break;}
            cx = 0;
            REP(jj, 1, n) if (!used[j] && a[jj].Y > a[j].Y) ++cx;
            S = S + C[kk][cx];
        }
        if (kk == -1) break;
    }
    cout << S;
}
