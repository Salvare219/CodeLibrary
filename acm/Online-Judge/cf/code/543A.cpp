#include<bits/stdc++.h>
using namespace std;


long long dp[505][505];
long long sum[505][505];
int mod;
int a[505];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,b;
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            for(int k=0;k<=b;k++)
            {
                if(j>=1&&k>=a[i])
                    sum[j][k]=(sum[j-1][k-a[i]]+dp[j][k])%mod;
                else
                    sum[j][k]=dp[j][k];
            }
        for(int j=0;j<=m;j++)
            for(int k=0;k<=b;k++)
                dp[j][k]=sum[j][k];
    }
    long long ans=0;
    for(int i=0;i<=b;i++)
        ans=(ans+dp[m][i])%mod;
    printf("%d\n",(int)ans);
    return 0;
}
