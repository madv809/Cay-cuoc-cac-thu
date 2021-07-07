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
#define FOD(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define RED(i, a, b) for (int i = (a); i >= (b); --i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array
#define ef else if
//#define lb lower_bound
#define one "bridge"
#define two "penguins"
#define lb long double
//#define double long double
//#define int LL

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 7;
const lb eps1 = 1e-16;
const lb eps2 = 1e-10;
int a[mxn], n, k, s, x, Vmi, Vmx, Vo;

signed main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
     cin >> n >> k >> s >> Vmi >> Vmx >> Vo;
     REP(i, 1, k) { scanf("%d", &x); a[x] = -1; }
     REP(i, 1, n) if (a[i] != -1) { x = i; break; }

     lb dis1 = (lb)(s)/(lb)(n - k), dis2 = (lb)(s)/(lb)(n);
     lb tmp1 = dis1, tmp2 = dis2, mi = 1e9, mx = -1e9;

     REP(i, x + 1, n) if (a[i] != -1)
     {
         mi = min(mi, tmp1 - tmp2);
         mx = max(mx, tmp1 - tmp2);
         tmp1 += dis1;
         tmp2 += dis2;
     } else tmp2 += dis2;

     lb l = 0, r = 1e17, mid, limit = (lb)(Vmx - Vmi);
     while (l < r - eps1)
     {
         mid = (l + r)/(lb)(2.0);
         if (mx - mi <= limit*mid) r = mid;
         else l = mid + eps1;
     }
     cout << setprecision(17) << l << endl;
     if (l == 0)
     {
         REP(i, 1, n) if (a[i] != -1)
            cout << i << ' ' << Vmx << endl;
        return 0;
     }

     lb V = (lb)(Vmx) - mx/l;
     cout << x << ' ' << V << endl;
     tmp1 = dis1; tmp2 = dis2;
     REP(i, x + 1, n) if (a[i] != -1)
     {
         cout << i << ' ' << (V + (tmp1 - tmp2)/l) << endl;
         tmp1 += dis1;
         tmp2 += dis2;
     } else tmp2 += dis2;
     tmp1 -= dis1; tmp2 -= dis2;
}
