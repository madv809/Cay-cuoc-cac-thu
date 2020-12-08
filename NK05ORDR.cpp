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
LL a[mxn], c[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        LL k, m, a, pos = 0;
        cin >> k >> m;
        a = k;
        while (a)
        {
            pos += a - (LL)pow(10LL, (LL)log10(a)) + 1;
            a /= 10;
        }
        if (m < pos) {cout << 0 << endl; continue;}
        if (pos == m) {cout << k << endl; continue;}
        if (k == (LL)pow(10LL, (LL)log10(k))) {cout << 0 << endl; continue;}
        a = k-1;

        while (1)
        {
            if (pos + a*10 + 9 - (LL)pow(10LL, (LL)log10(a*10)) + 1 <= m)
            {
                pos += a*10 + 9 - (LL)pow(10LL, (LL)log10(a*10)) + 1;
                a = a*10 + 9;
                if (pos == m)
                {
                    cout << a << endl;
                    break;
                }
            }
            else
            {
                cout << ((LL)pow(10LL, (LL)log10(a*10)) + m - pos - 1) << endl;
                break;
            }
        }
    }
}
