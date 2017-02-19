#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,s;
char maz[600][600];
bool v[600][600];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void dfs(int x,int y)
{
    v[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i],y1=y+dy[i];
        if(maz[x1][y1]=='.'&&v[x1][y1]==0)
            dfs(x1,y1);
    }
    if(s)maz[x][y]='X',s--;
}
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i+1]+1);
    int x,y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(maz[i][j]=='.') x=i,y=j;
    dfs(x,y);
    for(int i=1;i<=n;i++)
        puts(maz[i]+1);
    return 0;
}
