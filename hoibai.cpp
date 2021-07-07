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
#define lb lower_bound
#define one "bridge"
#define two "penguins"
//#define double long double
//#define int LL

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e9 + 7;
const long double eps = 0.00000001;
int a[mxn], n, k, s, x, Vmi, Vmx, Vo;

signed main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
     cin >> n >> k >> s >> Vmi >> Vmx >> Vo;
     REP(i, 1, k) { scanf("%d", &x); a[x] = -1; }
     long double para = (long double)(s)/(long double)(n - k); long double tmp = para, tmpp = (long double)(s)/n, kk = tmpp;
     long double mi = 1e9, mx = -1e9;

     REP(i, 1, n) if (a[i] != -1) { x = i; break; }
     REP(i, x + 1, n) if (a[i] != -1)
     {
         mi = min(mi, tmp - kk);
         mx = max(mx, tmp - kk);
         tmp += para;
         kk += tmpp;
     } else kk += tmpp;

     long double l = 0, r = 1e17, mid;
     while(l < r - eps)
     {
         mid = (l + r)/2.0;
         if (mx - mi <= (long double)(Vmx - Vmi)*mid - eps) r = mid;
         else l = mid + eps;
     }
     cout << setprecision(10) << l << endl;
     if (l == 0)
     {
         REP(i, x, n) if (a[i] != -1)
            cout << i << ' ' << Vmx << endl;
        return 0;
     }
     long double V = (long double)(Vmx) - (mx/l);
     tmp = para; kk = tmpp;
     cout << x << ' ' << setprecision(10) << V << endl;
     REP(i, x + 1, n) if (a[i] != -1)
     {
         cout << i << ' ' << setprecision(10) << (V + (tmp - kk)/l) << endl;
         tmp += para;
         kk += tmpp;
     } else kk += tmpp;
}
