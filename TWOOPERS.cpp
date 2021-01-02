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
 
const int mxn = 1e6 + 5;
const int INF = 1e9;
const LL BASE = 311;
string s, t;
int Z1[mxn], Z2[mxn], n;
 
void Z (int z[])
{
    string sf = t + '#' + s + '.';
    int n = sf.length(); int l, r;
 
    l = r = 0;
    for (int i = 0; i < n; ++i)
    {
        if (z[i - l] < r - i + 1) z[i] = z[i - l];
        else
        {
            l = i; r = max(r, i);
            while (sf[r - l] == sf[r]) ++r;
            z[i] = r - l; --r;
        }
    }
    n = s.length();
    for (int i = 0; i < n; ++i)
        z[i] = z[n/2 + i + 1];
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> s >> t;
    n = s.length();
    s = s + s;
    Z(Z1);
    //cout << s << endl;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    Z(Z2);
 
    LL res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (Z1[i] == n) res += n;
        else if (Z1[i] + Z2[2*n - (i + n - 1)- 1] == n - 1) ++res;
    }
    cout << res;
    /*FOR(i, 0, 2*n) cout << Z1[i] << ' '; cout << endl;
    FOR(i, 0, 2*n) cout << Z2[i] << ' ';*/
}
