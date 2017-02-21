#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int l,ty;
vector<int>gra[50000];
long long dp[2][50000],pre[50000];
void dfs(int s,int p)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
            dfs(y,s),dp[ty][s]=max(dp[ty][s],dp[ty][y]+1);
}
void dfs2(int s,int p,long long len)
{
    int y,m1=len,m2=0,f=p;dp[ty][s]=max(len,dp[ty][s]);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            if(dp[ty][y]+1>m1)m2=m1,f=y,m1=dp[ty][y]+1;
            else if(dp[ty][y]+1>m2)m2=dp[ty][y]+1;
        }
    l=max(m1+m2,l);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            if(y==f)dfs2(y,s,m2+1);
            else dfs2(y,s,m1+1);
        }
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2)
    {
        int x,y;
        for(int i=1;i<=n;i++)gra[i].clear(),dp[0][i]=0;
        for(int i=1;i<n;i++)
            scanf("%d%d",&x,&y),gra[x].push_back(y),gra[y].push_back(x);
        l=0;ty=0;dfs(1,0);dfs2(1,0,0);
        for(int i=1;i<=q;i++)gra[i].clear(),dp[1][i]=0;
        for(int i=1;i<q;i++)
            scanf("%d%d",&x,&y),gra[y].push_back(x),gra[x].push_back(y);
        ty=1;dfs(1,0);dfs2(1,0,0);dp[0][0]=dp[0][n];dp[1][0]=dp[1][q];
        sort(dp[0],dp[0]+n);sort(dp[1],dp[1]+q);pre[q]=0;
        for(int i=q-1;i>-1;i--)pre[i]=pre[i+1]+dp[1][i];
        int p=0;
        long long sum=0;
        for(int i=n-1;i>-1;i--)
        {
            while(p<q&&dp[1][p]+dp[0][i]+1<=l)p++;
            sum+=pre[p]+(q-p)*(dp[0][i]+1)+p*l;
        }
        printf("%.3f\n",1.0*sum/n/q);
    }
	return 0;
}
