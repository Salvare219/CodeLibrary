#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

long long counters[1010];
long long sum[1010];

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    int d, n, m;
    scanf("%d%d%d",&d, &n, &m);
    for (int i=1; i<=d; i++)
        for(int j=1; j<=n; j++)
        {
            int x;
            scanf("%d", &x);
            counters[j]+=x;
        }
    for (int j=1; j<=n; j++)
        sum[j] = counters[j] + sum[j-1];

    long long ans = 1;
    for (int i=2; i<=n-m+1; i++)
        if(sum[ans+m-1] - sum[ans-1]<sum[i+m-1] - sum[i-1])
            ans = i;
    printf("%I64d %I64d\n", ans, sum[ans+m-1] - sum[ans-1]);

    return 0;
}
