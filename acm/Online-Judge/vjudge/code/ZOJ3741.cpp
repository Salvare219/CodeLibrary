#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[2000];
int dp[500];
int main()
{
    int l,n,x,y;
    while(~scanf("%d%d%d%d",&l,&n,&x,&y))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            int sol=0;
            for(int j=i;j<min(n,i+x);j++)
                if(min(l+1,5)>=a[j])sol++;
            for(int j=i+x;j<min(n,i+x+y);j++)
                if(a[j]==0)sol++;
            dp[min(n,i+x+y)]=max(dp[min(n,i+x+y)],dp[i]+sol);
            dp[i+1]=max(dp[i+1],dp[i]+(l>=a[i]));
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
