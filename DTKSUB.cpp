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
const int INF = 1e9;
const LL BASE = 311;
int n, k;
ULL Hash[mxn], powB[mxn];
 
ULL get_Hash (int i, int j)
{
    return (Hash[j] - Hash[i - 1]*powB[j - i + 1]);
}
 
bool tf (int x)
{
    vector<ULL> a;
    for (int i = 1; i <= n - x + 1; ++i)
        a.push_back(get_Hash(i, i + x - 1));
    sort(a.begin(), a.end());
    int s = 1;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != a[i - 1]) s = 1;
        else ++s;
        if (s == k) return 1;
    }
    return 0;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> k;
    string s; cin >> s; s = '1' + s;
    REP(i, 1, n) Hash[i] = Hash[i - 1]*BASE + s[i];
    powB[0] = 1;
    REP(i, 1, n) powB[i] = BASE*powB[i - 1];
 
    int l = 0, r = n - k + 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (tf(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;
}
