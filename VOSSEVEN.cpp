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
 
LL res[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    string s;
    cin >> s;
    s += '1';
    int n = s.length();
    LL x = 0;
    FOR(i, 0, n)
    {
        if (s[i] == '7') ++x;
        else
        {
            REP(j, 1, (int)x) res[j] += x - (LL)j + 1;
            x = 0;
        }
    }
    FOR(i, 1, n) if (res[i]) printf("%d %lli\n", i, res[i]);
}
 
