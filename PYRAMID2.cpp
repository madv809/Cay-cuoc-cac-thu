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
#define ef else if

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t = 0, res = 0;
    int l = 0, r = s.length() - 1;

    REP(i, l, r) if (s[i] == '<') ++res;
    while (l < r && s[l] == '<') ++l;
    while (r > l && s[r] == '>') --r;

    if (l == r) { cout << 0; return 0; }
    for (int i = l + 1; i <= r; ++i)
    {
        if (s[i - 1] == '<') ++t;
        else t = max(0, t - 1);
    }
    res = r - res + 1 + t;
    cout << res;
}

