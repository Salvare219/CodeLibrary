#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int s[4005][4005],dp[805][4005];
int q[4005],c[4005],t,f;
int n,k,x;
inline void push(int i,int j)
{
    if(t==f)q[t]=j,c[t++]=j;
    else
    {
        int l=j,r=n,mid;x=q[t-1];
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(dp[i][j]-2*s[mid][j]+s[j][j]>dp[i][x]-2*s[mid][x]+s[x][x])l=mid;
            else r=mid-1;
        }
        l++;
        if(l>n);
        else if(l<=c[t-1])t--,push(i,j);
        else q[t]=j,c[t++]=l;
    }
}
int main()
{
    scanf("%d%d",&n,&k);x=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            while(x<'0')x=getchar();
            s[i][j]=x-'0'+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            x=0;
        }
    for(int i=1;i<=n;i++)dp[1][i]=s[i][i];
    for(int i=1;i<k;i++)
    {
        t=0;f=0;
        for(int j=1;j<=i;j++)
            push(i,j);
        for(int j=i+1;j<=n;j++)
        {
            while(f+1<t&&c[f+1]<=j)f++;
            dp[i+1][j]=dp[i][q[f]]+s[j][j]+s[q[f]][q[f]]-2*s[j][q[f]];
            push(i,j);
        }
    }
    printf("%d\n",dp[k][n]/2);
    return 0;
}
