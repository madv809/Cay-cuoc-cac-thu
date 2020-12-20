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

const int mxn = 1e5 + 5;
LL f[101][10001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m; cin >> n >> m;
    REP(i, 1, n)
    {
        int w, v, a; cin >> w >> v >> a;   // khối lượng, giá trị, số lượng
        FOR(j, 0, w)
        {
            deque<int> s;
            for (int x = j; x <= m; x += w)
            {
                while (s.size() && s.front() < x - a*w) s.pop_front();
                while (s.size() && f[i-1][s.back()] + (x - s.back())/w*v <= f[i-1][x]) s.pop_back();
                s.push_back(x);
                f[i][x] = max(f[i-1][x], f[i-1][s.front()] + (x - s.front())/w*v);
            }
        }
    }
    cout << f[n][m];
}

