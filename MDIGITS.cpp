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
const LL MOD = 1e9+7;
const int mxn = 1e6+5;
LL f[10][10][10];
LL a[100];

vector<LL> get (LL x)
{
    vector<LL> res(10); REP(i, 0, 9) res[i] = 0;
    LL k = x; LL t = (LL)log10(x) + 1, tt = t;
    while (k)
    {
        a[tt--] = k%10LL;
        k /= 10LL;
    } a[t+1] = 0;
    //REP(i, 1, t) cout << a[i] << ' '; exit(0);
    for (int i = 1; i < t; ++i)
        REP(j, 1, 9) REP(tt, 0, 9) res[tt] += f[i][j][tt];

    tt = t;
    --tt;
    for (LL i = 1; i <= t; ++i)
    {
        LL j = 0; if (i==1) j = 1;
        for (; j < a[i]; ++j)
            for (LL tk = 0; tk <= 9; ++tk) res[tk] += f[t-i+1][j][tk];
        x%=(LL)pow(10LL, (LL)tt);
        res[a[i]] += x + 1;
        --tt;
    }
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(j, 0, 9) f[1][j][j] = 1; // f[i][j][t] = số chữ số t trong dãy độ dài i có j là chữ số đứng đầu
    REP(i, 2, 10)
        REP(j, 0, 9)
            REP(t, 0, 9)
            {
                REP(k, 0, 9) f[i][j][t] += f[i-1][k][t];
                f[i][j][t] += (j==t)*(LL)pow(10LL, (LL)(i-1));
            }
    LL a, b;
    while ((cin >> a >> b))
    {
        if (a==b && a== 0) break;
        if (a > b) swap(a, b);
        vector<LL> x(10); x = get(b);
        vector<LL> y(10); y = get(a - 1);
        /*cout << a << ' ' << b << endl;
        for (int i : y) cout << i << ' '; cout << endl;
        for (int i : x) cout << i << ' ';
        return 0;*/
        for (int i = 0; i < 10; ++i) cout << (x[i] - y[i]) << ' '; cout << endl;
    }
}
