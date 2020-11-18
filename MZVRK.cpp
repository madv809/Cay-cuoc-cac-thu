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
#define ULL unsigned long long

using namespace std;

ULL get (ULL x, ULL xx)
{
    ULL res = 0, a = x;
    for (ULL i = 0; i < xx; ++i)
    {
        if (a&((ULL)1 << i)) a -= ((ULL)1 << i);
        res += (1 + (x >> (i + (ULL)1)))*((ULL)1 << i);
        if (a + ((ULL)1 << i) > x) res -= ((ULL)1 << i);
    }
    if (x) res += ((ULL)1 << xx);
    return res;
}

ULL L, R, ll = 0, rr = 0;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> L >> R;
    while (((ULL)1 << (ll + 1)) <= L - 1) ++ll;
    while (((ULL)1 << (rr + 1)) <= R) ++rr;
    cout << (get(R, rr) - get(L - 1, ll));
    /*int res = 0;
    for (int i = 1; i <= R; ++i) res += i&(-i); cout << res << endl;
    res = 0;
    for (int i = 1; i <= L - 1; ++i) res += i&(-i); cout << res;*/
}
