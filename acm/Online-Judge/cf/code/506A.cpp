#include<bits/stdc++.h>
using namespace std;


int cnt[90005];
int dp[90005][700];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,d,x;scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
        scanf("%d",&x),cnt[x]++;
    int ans=0;
    for(int i=0;i<=30001;i++)
        for(int j=0;j<600;j++)
            dp[i][j]=-50000;
    dp[d][300]=cnt[d];
    for(int i=d;i<30001;i++)
        for(int j=1;j<600;j++)
            if(dp[i][j]!=-50000)
            {
                ans=max(ans,dp[i][j]);
                dp[i+d+j-300][j]=max(dp[i+d+j-300][j],dp[i][j]+cnt[i+d+j-300]);
                dp[i+d+j-300+1][j+1]=max(dp[i+d+j-300+1][j+1],dp[i][j]+cnt[i+d+j-300+1]);
                if(d+j-300>1)dp[i+d+j-300-1][j-1]=max(dp[i+d+j-300-1][j-1],dp[i][j]+cnt[i+d+j-300-1]);
            }
    printf("%d\n",ans);
    return 0;
}
