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
#define BASE 1000000000000000000ULL
 
using namespace std;
 
const int mxn = 1e5 + 5;
const int INF = 1e9;
const LL MOD = 1e9 + 7;
struct BigInt { ULL h, l; };
const BigInt zero = {0, 0};
const BigInt one = { 0, 1};
 
void operator += (BigInt &a, const BigInt b) {
    a.l += b.l;
    if (a.l > BASE) a.l -= BASE, a.h += 1;
    a.h += b.h;
}
void operator -= (BigInt &a, const BigInt b) {
    if (a.l < b.l) a.l += BASE-b.l, a.h -= 1;
    else a.l -= b.l;
    a.h -= b.h;
}
void print(BigInt a) {
    if (a.h == 0) printf("%llu", a.l);
    else printf("%llu%018llu", a.h, a.l);
}
 
BigInt f[2][mxn];
pLL a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; LL s; cin >> s >> n;
    REP(i, 1, n) cin >> a[i].X >> a[i].Y;
 
    f[0][0] = one; f[1][0] = one;
    int x = 0;
    REP(i, 1, n)
    {
        x ^= 1;
        for (LL j = 1; j <= s; ++j)
        {
            f[x][j] = f[x^1][j];
            LL k = j - a[i].X;
            if (k >= 0) f[x][j] += f[x][k];
            k = j - a[i].X*(a[i].Y + 1);
            if (k >= 0) f[x][j] -= f[x^1][k];
        }
    }
    print(f[x][s]);
}
