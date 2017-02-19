#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int p[5000];
bool v[5000];
int dp[5000];
int sum[5000];
int mod=1000000007;
int main()
{
//    freopen("1.txt", "r", stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i);
    dp[1]=2;sum[1]=2;
    for(int i=2;i<=n;i++)
    {
        dp[i]=(sum[i-1]-sum[p[i]-1]+2)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
    }
    printf("%d\n",(sum[n]+mod)%mod);
    return 0;
}