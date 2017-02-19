#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int sum[1005],a[1005],b[1005];
int dp[500150];
int dp1[500150];
bool vis[500150];
#include<queue>
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i),b[i]*=k;
    for(int i=0;i<n;i++)
        sum[i]=b[i]-a[i];
    queue<int>q,q1;
    q.push(11005);
    for(int i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        memcpy(dp1,dp,sizeof(dp));
        while(!q.empty())
        {
            int s=q.front();q.pop();
            if(vis[s+sum[i]]==0)
                vis[s+sum[i]]=1,q1.push(s+sum[i]);
            if(vis[s]==0)
                vis[s]=1,q1.push(s);
            dp1[s+sum[i]]=max(dp[s]+a[i],dp1[s+sum[i]]);
        }
        memcpy(dp,dp1,sizeof(dp));
        while(!q1.empty())
        {
            int s=q1.front();q1.pop();
            q.push(s);
        }
    }
    if(dp[11005]==0) printf("-1\n");
    else printf("%d\n",dp[11005]);
    return 0;
}

