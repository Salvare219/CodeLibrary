#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char str[1444][1444];
bool vis[1111][1111];
int bf[1111][1111];
int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int bfs(int x,int y)
{
    queue<pair<int,int> > q;
    q.push(make_pair(x*10000+y,0));
    int s,x1,y1,d;
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;bf[x][y]=0;
    while(!q.empty())
    {
        s=q.front().first;
        d=q.front().second;
        q.pop();
        x=s/10000;y=s%10000;
        for(int i=0;i<4;i++)
        {
            x1=x+dx[i];y1=y+dy[i];
            if(vis[x1][y1]==0 && str[x1][y1]!='T' && str[x1][y1])
            {
                vis[x1][y1]=1;bf[x1][y1]=d+1;
                q.push(make_pair(x1*10000+y1,d+1));
            }
        }
    }
    return 99999999;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int n,m;
    memset(str,0,sizeof(str));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",str[i+1]+1);
    memset(bf,0x3f,sizeof(bf));
    int ans;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='E')
                bfs(i,j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='S')
                ans=bf[i][j];
    int fl=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]>='1' && str[i][j]<='9')
                if(bf[i][j]<=ans) fl+=str[i][j]-'0';
    printf("%d\n",fl);
    return 0;
}
