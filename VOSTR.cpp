
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
ULL HashA[mxn], HashB[mxn], powB[mxn];
int la, lb;
string a, b;
 
ULL get_HashA (int i, int j)
{
    return (HashA[j] - HashA[i - 1]*powB[j - i + 1]);
}
 
ULL get_HashB (int i, int j)
{
    return (HashB[j] - HashB[i - 1]*powB[j - i + 1]);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
 
    cin >> la >> lb;
    cin >> a >> b;
 
    REP(i, 1, la) HashA[i] = HashA[i - 1]*BASE + int(a[i - 1]);
    REP(i, 1, lb) HashB[i] = HashB[i - 1]*BASE + int(b[i - 1]);
    powB[0] = 1;
    int k = max(la, lb);
    for (int i = 1; i <= k; ++i) powB[i] = powB[i - 1]*BASE;
 
    int q; cin >> q;
    REP(i, 1, q)
    {
        int l, r, u, v;
        scanf("%d%d%d%d", &l, &r, &u, &v);
 
        int x = min(r - l, v - u) + 1;
        int l1 = l - 1, r1 = l + x;
 
        while (l1 < r1)
        {
            int mid = (l1 + r1 + 1) >> 1;
            if (get_HashA(l, mid) != get_HashB(u, u + mid - l)) r1 = mid - 1;
            else l1 = mid;
        }
 
        if (l1 == l - 1)
        {
            if (a[l - 1] < b[u - 1]) cout << "<";
            else if (a[l - 1] == b[u - 1]) cout << "=";
            else cout << ">";
        }
        else if (l1 >= r)
        {
            if (r - l < v - u) cout << "<";
            else if (r - l == v - u) cout << "=";
            else cout << ">";
        }
        else
        {
            if (a[l1] < b[u + l1 - l]) cout << "<";
            else if (a[l1] == b[u + l1 - l]) cout << "=";
            else cout << ">";
        }
    }
}
