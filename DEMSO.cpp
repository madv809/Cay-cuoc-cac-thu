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

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
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

using namespace std;
const int mxn = 1094783;
const LL INF = 1e18;
const LL MOD = 790972;
const int BASE = 10000;
LL dp[10][17][2][2][17][2];
bool vis[10][17][2][2][17][2];
string sa, sb;
int a[17], b[17], d, k;

//        số trước đó   chữ số thứ i    > a      < b      số lượng vt xấu    só 0 đứng đầu
LL solve (int pre     , int i,        bool s_a, bool s_b, int kk,           bool start_count)
{
    if (i == sb.length()) return (kk <= k);
    LL &ans = dp[pre][i][s_a][s_b][kk][start_count];
    bool &vist = vis[pre][i][s_a][s_b][kk][start_count];
    if (vist) return ans;
    vist = 1;

    int u, v;
    if (s_a && s_b) { u = 0, v = 9; }
    else if (s_a && !s_b) { u = 0, v = b[i]; }
    else if (!s_a && s_b) { u = a[i], v = 9; }
    else { u = a[i]; v = b[i]; }

    for (int ii = u; ii <= v; ++ii)
        ans += solve(ii, i + 1, s_a||(ii > a[i]), s_b||(ii < b[i]), kk + (start_count&&(abs(ii - pre) <= d)), start_count||(ii > 0));
    return ans;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> sa >> sb >> d >> k;
    while (sa.length() < sb.length()) sa = '0' + sa;
    for (int i = 0; i < sa.length(); ++i)
    {
        a[i] = (int)(sa[i] - '0');
        b[i] = (int)(sb[i] - '0');
    }

    LL res = 0;
    for (int i = a[0]; i <= b[0]; ++i)
        res += solve(i, 1, i > a[0], i < b[0], 0, (i != 0));
    cout << res;
    //cout << sa << ' ' << sb << ' ' << d << ' ' << k;
}
