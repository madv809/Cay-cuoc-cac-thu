#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
#include <bitset>
#include <unordered_map>

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array
#define ef else if
#define lb lower_bound

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 123;
LL f[mxn][15][15], c[15][15], res[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n = 1e4;
    REP(i, 2, n) REP(j, 0, 10) REP(k, 0, 10 - j)
    {
        if (j > 0)
            (f[i][j][k] = (LL)(j)*f[i - 1][j - 1][k + 1]%MOD)%=MOD;
        if (k > 0)
            (f[i][j][k] += (LL)(k)*f[i - 1][j + 1][k - 1] + (LL)(k)*f[i - 1][j][k - 1]%MOD)%=MOD;
    }

    REP(i, 0, 10) c[i][0] = 1;
    REP(i, 1, 10) REP(j, 1, i) (c[i][j] += c[i - 1][j - 1] + c[i - 1][j])%=MOD;

    res[1] = 5;
    REP(i, 2, n)
    {
        res[i] = res[i - 1];
        REP(x, 1, 9) if (x&1) // đặt số lẻ ở đầu dãy
        {
            REP(j, 0, 10) REP(k, 0, 10 - j)
            {

                // số vừa đặt có xuất hiện trong dãy phía sau
                if (j > 0)
                    (res[i] += c[5][j - 1]*c[4][k]*f[i - 1][j][k]%MOD)%=MOD;

                // số vừa đặt không xuất hiện trong dãy phía sau
                (res[i] += c[5][j]*c[4][k]*f[i - 1][j][k])%=MOD;
            }
        }
        else // đặt số chẵn ở đầu dãy
        {
            REP(j, 0, 10) REP(k, 0, 10 - j)
            // chỉ có một trường hợp thỏa mãn
            if (k > 0)
            (res[i] += c[4][j]*c[5][k - 1]*f[i - 1][j][k]%MOD)%=MOD;
        }
    }
    //13 15 17 19 31 35 37 39 51 53 57 59 71 73 75 79 91 93 95 97 //16
    //22, 44, 66, 88 //4

    while (cin >> n)
    {
        if (n > 1e4) cout << "out of mem";
        cout << res[n] << endl;
    }
}
