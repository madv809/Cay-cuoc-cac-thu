#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;
int a[20001], t, n;

struct cmp{ bool operator()(int a, int b){return a > b;}};

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        priority_queue <int, vector<int>, cmp > heap;
        REP(i, 1, n) {scanf("%d", &a[i]); heap.push(a[i]);}
        LL res = 0;
        while (heap.size() > 1)
        {
            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();
            res += a + b;
            heap.push(a + b);
        }
        printf("%lli\n", res);
    }
}
