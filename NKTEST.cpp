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
vector<pii> a, b;
int c[2];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    string s;
    while (cin >> s)
    {
        if (s == "ENDPROGRAM") break;
        if (s == "IF") a.push_back({1, 1});
        else if (s == "ELSE") a.push_back({2, 1});
        else if (s == "END_IF")
        {
            c[0] = c[1] = 1;
            int i = 0;
            while (1)
            {
                pii x = a.back();
                c[i] *= x.Y;
                a.pop_back();
                if (x.X == 1) break;
                if (x.X == 2) ++i;
            }
 
            int x = c[0] + c[1];
            a.push_back({0, x});
        }
    }
    int res = 1;
    for (pii i : a) res *= i.Y;
    cout << res;
}
