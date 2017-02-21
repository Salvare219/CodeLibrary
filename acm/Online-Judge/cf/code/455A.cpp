#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long cnt[100050];
long long dp[100050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x),cnt[x]++;
    for(int i=2;i<100005;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i-2]*(i-2));
    }
    printf("%I64d\n",dp[100004]);
    return 0;
}
