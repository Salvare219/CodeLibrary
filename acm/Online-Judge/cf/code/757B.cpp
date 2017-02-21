#include<bits/stdc++.h>
using namespace std;


int a[100050];
int dp[100050];
int prim[100050],k;
bool vis[100050];
int mi[100050];
void cal()
{
	for(int i=2;i<100005;i++)
	{
		if(vis[i]==0) prim[k++]=i,mi[i]=i;
		for(int j=0;j<k&&prim[j]*i<100005;j++)
		{
			vis[prim[j]*i]=1;
			mi[prim[j]*i]=prim[j];
			if(i%prim[j]==0) break;
		}
	}
}
int main()
{
    //freopen("2.txt","w",stdout);
    cal();
    int n,k=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        int x=a[i],las=-1;
        while(x!=1)
        {
            int y=mi[x];
            if(y!=las)
                dp[las=y]++;
            x/=y;
        }
    }
    int ans=1;
    for(int i=2;i<=100005;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
