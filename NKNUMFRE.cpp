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
 
const int mxn = 2e5 + 5;
const LL INF = 1e18;
const LL BASE = 311;
 
int gcd (int a, int b)
{
    while (b)
    {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int a, b; cin >> a >> b;
    int res = 0;
    REP(i, a, b)
    {
        int x = i, y = 0;
        while (x)
        {
            (y *= 10) += x%10;
            x /= 10;
        }
        if (gcd(i, y) == 1) ++res;
    }
    cout << res;
}
