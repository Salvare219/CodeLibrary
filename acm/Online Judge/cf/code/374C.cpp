#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>g[1000050];
int dp[1000050];
bool v[1000050];
bool w[1000050];
char maz[1100][1100];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m;
char lb[]="DIMAD";
#include<queue>
void bfs(int x,int y)
{
    int s=x,t=y;
    int x1,y1,z;
    queue<int>q;
    q.push(x*100000+y*10);
    while(!q.empty())
    {
        x=q.front()/100000;
        y=q.front()%100000/10;
        z=q.front()%10;q.pop();
        for(int i=0;i<4;i++)
        {
            x1=x+dx[i];y1=y+dy[i];
            if(maz[x1][y1]==lb[z+1])
            {
                if(lb[z+1]=='D')
                    g[(s-1)*1000+t-1].push_back((x1-1)*1000+y1-1);
                else
                {
                    q.push(x1*100000+y1*10+z+1);
                    if(lb[z+1]=='A') w[(s-1)*1000+t-1]=1;
                }
            }
        }
    }
}
bool f;
int dfs(int s)
{
    if(dp[s]!=-1)return dp[s];
    v[s]=1;dp[s]=0;
    for(int i=0;i<g[s].size()&&f==0;i++)
    {
        if(v[g[s][i]]){f=1;return 0;}
        dp[s]=max(dp[s],dfs(g[s][i]));
    }
    v[s]=0;
    return dp[s]+=w[s];
}
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i+1]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[(i-1)*1000+j-1]=-1;
            if(maz[i][j]=='D')bfs(i,j);
        }
    int ans=0;f=0;
    for(int i=0;i<n&&f==0;i++)
        for(int j=0;j<m&&f==0;j++)
            if(maz[i+1][j+1]=='D')
            {
                ans=max(ans,dfs(i*1000+j));
                if(f)break;
            }
    if(f)puts("Poor Inna!");
    else
    {
        if(ans)printf("%d\n",ans);
        else puts("Poor Dima!");
    }
    return 0;
}
