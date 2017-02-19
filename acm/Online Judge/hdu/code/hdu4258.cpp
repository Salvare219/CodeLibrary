#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long x[1000050],dp[1000050];
int sta[1000050];
bool exam(int a,int b,long long c)
{
    return dp[b]+x[b]*x[b]-dp[a]-x[a]*x[a]<=c*(x[b]-x[a]);
}
bool xmult(int a,int b,int c)
{
    return (dp[b]+x[b]*x[b]-dp[a]-x[a]*x[a])*(x[c]-x[a])-(x[b]-x[a])*(dp[c]+x[c]*x[c]-dp[a]-x[a]*x[a])>=0;
}
int main()
{
    int n,c;
    while(~scanf("%d%d",&n,&c)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%I64d",x+i);
        int t=0,f=1,y;sta[0]=0;
        for(int i=0;i<n;i++)
        {
            while(t+1<f&&exam(sta[t],sta[t+1],x[i]<<1))t++;
            y=sta[t];
            dp[i+1]=dp[y]+(x[i]-x[y])*(x[i]-x[y])+c;
            while(t+1<f&&xmult(sta[f-2],sta[f-1],i+1))f--;
            sta[f++]=i+1;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
