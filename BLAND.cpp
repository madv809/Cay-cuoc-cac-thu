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
#define ar array

using namespace std;

const int mxn = 3e2 + 5;
int a[mxn][mxn], b[mxn][mxn], kk, gmi[mxn][mxn][mxn], gmx[mxn][mxn][mxn];
LL f[mxn], res;
deque<int> smi, smx;
int m, n;

void solve()
{
    //truy xuat nhanh           g[i][j][k] = min/max tại cột thứ i, từ hàng j -> k;
    REP(i, 1, m)
        REP(j, 1, n)
        {
            gmx[i][j][j] = gmi[i][j][j] = a[j][i];
            for (int k = j - 1; k >= 1; --k)
            {
                gmi[i][j][k] = min(a[k][i], gmi[i][j][k+1]);
                gmx[i][j][k] = max(a[k][i], gmx[i][j][k+1]);
            }
        }

        memset(f, 0, sizeof(f));
        LL mi, mx;
        REP(i, 1, n)
        {
            for (int k = 1; k <= i; ++k) // chiều cao của hcn đang xét
            {
                smi.clear(); smx.clear(); smi.push_back(1); smx.push_back(1);
                mi = mx = 1;
                REP(j, 1, m)
                {
                        while (smi.size() && gmi[smi.back()][i][i-k+1] > gmi[j][i][i-k+1]) smi.pop_back(); smi.push_back(j);
                        while (smx.size() && gmx[smx.back()][i][i-k+1] < gmx[j][i][i-k+1]) smx.pop_back(); smx.push_back(j);

                        // kiểm tra xem có ô đất nào không hợp lệ thì bỏ ra
                        while (smx.size() && gmx[smx.front()][i][i-k+1] - gmi[j][i][i-k+1] > kk)
                        {
                            mx = smx.front() + 1;
                            smx.pop_front();
                        }
                        while (smi.size() && gmx[j][i][i-k+1] - gmi[smi.front()][i][i-k+1] > kk)
                        {
                            mi = smi.front() + 1;
                            smi.pop_front();
                        }

                        if (mi <= j && mx <= j) f[i] = max(f[i], (j - max(mi, mx) + 1)*k*1LL);
                        res = max(res, f[i] + f[i - k]);
                }
            }
            f[i] = max(f[i], f[i-1]);
        }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &kk);
    REP(i, 1, n) REP(j, 1, m) scanf("%d", &a[i][j]);
    res = -1e17;
    solve();
    REP(i, 1, n) REP(j, 1, m)
        b[j][n - i + 1] = a[i][j];
    swap(n, m);
    REP(i, 1, n) REP(j, 1, m) a[i][j] = b[i][j];
    solve();
    //cout << endl; REP(i, 1, n) {REP(j, 1, m) cout << a[i][j] << ' '; cout << endl;}
    //cout << gmi[1][3][3] << endl;
    cout << res;
}
