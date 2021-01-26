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
LL f, d;
 
bool g (LL f, LL x)
{
    int mid = 1 << (f - 1);
    if (x == mid) return 1;
    if (x < mid) return !g(f - 1, mid - x);
    return g(f - 1, x - mid);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    while (cin >> f >> d)
    {
        if (f == d && f == 0) return 0;
        if (g(f, d)) cout << "D\n";
        else cout << "U\n";
    }
}
 
