#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   


int prim[35],dp[155][35];
void cal()
{
    int k=0;
    bool vis[151]={0};
    for(int i=2;i<=150;i++)
    {
        if(!vis[i]) 
        {
            dp[i][k]=1;
            prim[k++]=i;
        }
            
        for(int j=0;j<k && prim[j]*i<=150;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}
void caldp()
{
    for(int i=2;i<151;i++)
    {
        for(int j=0;j<35;j++)
        if(dp[i][j]>0)
        {
            for(int k=j;k<35;k++)
                if(i+prim[k]<151) dp[i+prim[k]][k]+=dp[i][j];
        }
    }
}
int main()
{
    memset(dp,0,sizeof(dp));
    cal();
    caldp();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0;
        scanf("%d",&n);
        for(int i=0;i<35;i++)
            if(dp[n][i]>-1) sum+=dp[n][i];
        printf("%d\n",sum);
    }
    return 0;
}