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
int l[mxn];
vector<int> prime;
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int a, n; cin >> a >> n;
 
    REP(i, 2, n)
    {
        if (!l[i])
        {
            l[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= l[i] && prime[j]*i <= n; ++j)
            l[prime[j]*i] = prime[j];
    }
 
    for (int i : prime) if (i >= a) cout << i << endl;
}
