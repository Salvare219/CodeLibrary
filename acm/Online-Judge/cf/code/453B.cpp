#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[2000],b[2000];
int p[100];
int dp[105][1<<17];
int prim[2050],k;
int pre[105][1<<17];
int pp[105][1<<17];
bool vis[2050];
void cal()
{
	for(int i=2;i<2000;i++)
	{
		if(vis[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<2000;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int fin[200];
int sa[200];
int v[200];
int ol[200];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),ol[i]=a[i];
    cal();
    for(int i=2;i<=60;i++)
    {
        int c=0;
        for(int j=0;prim[j]<=i;j++)
            if(i%prim[j]==0)
            {
                c|=1<<j;
            }
        p[i]=c;
    }
    sort(a,a+n);
    int z=min(n,16);
    for(int i=1;i<=z;i++)
        b[i]=a[n-z+i-1];
    int lim=1<<16;
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<lim;i++)
        dp[0][i]=0;
    for(int i=1;i<=z;i++)
    {
        for(int j=0;j<lim;j++)
        {
            for(int s=1;s<=60;s++)
                if((p[s]&j)==0)
                {
                    if(dp[i][j|p[s]]>dp[i-1][j]+abs(s-b[i]))
                    {
                        dp[i][j|p[s]]=dp[i-1][j]+abs(s-b[i]);
                        pre[i][j|p[s]]=j;
                        pp[i][j|p[s]]=s;
                    }
                }
        }
    }
    int ans=0x3fffffff,f=0;
    for(int i=0;i<lim;i++)
        if(ans>dp[z][i])
        {
            ans=dp[z][i];
            f=i;
        }
    int cnt=z;
    do
    {
        fin[cnt]=pp[cnt][f];
        f=pre[cnt][f];
    }while(cnt--);
    int k=0;
    for(int i=0;i<n-z;i++)
        sa[k++]=1;
    for(int i=1;i<=z;i++)
        sa[k++]=fin[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(v[j]==0&&ol[i]==a[j])
            {
                v[j]=1;
                printf("%d ",sa[j]);
                break;
            }
    putchar(10);
	return 0;
}

