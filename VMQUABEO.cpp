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

const int mxn = 1e6 + 5;
int a[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, l, d; cin >> n >> l >> d;
    REP(i, 1, n) scanf("%d", &a[i]);
    LL res = 0, x = 1; deque<int> smi, smx;
    REP(i, 1, n)
    {
        while (smi.size() && a[smi.back()] >= a[i]) smi.pop_back();
        while (smx.size() && a[smx.back()] <= a[i]) smx.pop_back();
        smx.push_back(i); smi.push_back(i);
        while (a[smx.front()] - a[smi.front()] > d)
        {
            if (smi.front() < smx.front())
            {
                x = smi.front() + 1;
                smi.pop_front();
            }
            else
            {
                x = smx.front() + 1;
                smx.pop_front();
            }
        }
        if (i - x >= l) res += i - x - l + 1;
    }
    cout << res;
}

