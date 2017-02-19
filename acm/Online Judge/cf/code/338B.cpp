#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


vector<int> gra[100050];
bool sa[100050];
bool ha[100050];
int dp[100050][2];
int n,m,d;
void dfs1(int s,int p)
{
    dp[s][0]=9999999;
    dp[s][1]=0;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            dfs1(gra[s][i],s);
            dp[s][1]+=dp[gra[s][i]][1];
            dp[s][0]=min(dp[s][0],dp[gra[s][i]][0]-1);
        }
    if(sa[s])
    {
        dp[s][1]++;
        dp[s][0]=min(dp[s][0],d);
    }
    if(dp[s][1]==m && dp[s][0]>=0) ha[s]=1;
}
void dfs2(int s,int p,int sz,int dd)
{
    if(sz+dp[s][1]==m && dp[s][0]>=0 && dd>=0) ha[s]=1;
    int sum=0;
    int m1=dd,m2=dd,fl=p;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            sum+=dp[gra[s][i]][1];
            if(dp[gra[s][i]][0]-1<m1)
            {
                m2=m1;
                m1=dp[gra[s][i]][0]-1;
                fl=gra[s][i];
            }
            else if(dp[gra[s][i]][0]-1<m2)
            {
                m2=dp[gra[s][i]][0]-1;
            }
        }
    if(sa[s]) sum++,m1=min(m1,d),m2=min(m2,d);
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            if(fl==gra[s][i]) dfs2(gra[s][i],s,sz+sum-dp[gra[s][i]][1],m2-1);
            else dfs2(gra[s][i],s,sz+sum-dp[gra[s][i]][1],m1-1);
        }
}
int main()
{
  //  freopen("1.txt","r",stdin);
    int x,y;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=0;i<m;i++)
        scanf("%d",&x),sa[x]=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    dfs1(1,-1);
    dfs2(1,-1,0,9999999);
    int pl=0;
    for(int i=1;i<=n;i++)
        if(ha[i]) pl++;
    printf("%d\n",pl);
    return 0;
}
