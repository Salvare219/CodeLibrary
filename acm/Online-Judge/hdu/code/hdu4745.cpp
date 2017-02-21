#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 2010;
int n, n2, ans;
int a[maxn];
int dp[maxn][maxn];

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        for (int i=1;i<=n;i++) a[i+n] = a[i];
        memset(dp, 0, sizeof(dp));
        n2 = n+n;
        for (int i=1;i<=n2;i++) dp[i][i] = 1;
        for (int l=2;l<=n;l++)
            for (int i=1;i+l-1<=n2;i++)
            {
                int j = i+l-1;
                dp[i][j] = max(dp[i+1][j-1] + (a[i] == a[j] ? 2 : 0), max(dp[i+1][j], dp[i][j-1]));
            }
        ans = 0;
        for (int i=1;i<=n;i++) ans = max(ans, dp[i][i+n-1]);
        for (int i=1;i<=n;i++) ans = max(ans, dp[i][i+n-2]+1);
        printf("%d\n", ans);
    }
    return 0;
}
