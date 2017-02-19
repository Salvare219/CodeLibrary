#include<bits/stdc++.h>
using namespace std;


int deg[2050][2050];
queue<pair<int,int> >q;
int v[2050][2050];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char lib[]="<>^v";
char maz[2050][2050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",maz[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((i+j)%2==0&&maz[i][j]=='.')
            {
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(maz[x][y]=='.')
                    {
                        deg[x][y]++;
                        deg[i][j]++;
                    }
                }
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(deg[i][j]==1)
                q.push(make_pair(i,j));
    while(!q.empty())
    {
        int px=q.front().first,py=q.front().second;
        q.pop();
        if(v[px][py])continue;
        for(int i=0;i<4;i++)
        {
            int x=px+dx[i],y=py+dy[i];
            if(maz[x][y]=='.'&&v[x][y]==0)
            {
                v[x][y]=1;
                v[px][py]=1;
                deg[x][y]=0;
                deg[px][px]=0;
                maz[px][py]=lib[i];
                maz[x][y]=lib[i^1];
                for(int j=0;j<4;j++)
                {
                    int cx=x+dx[j],cy=y+dy[j];
                    if(maz[cx][cy]=='.'&&v[cx][cy]==0)
                    {
                        deg[cx][cy]--;
                        if(deg[cx][cy]==1)
                        {
                            q.push(make_pair(cx,cy));
                        }
                    }
                }
            }
        }
    }
    int g=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(maz[i][j]=='.')
                g=1;
    if(g)puts("Not unique");
    else
    {
        for(int i=1;i<=n;i++)
            printf("%s\n",maz[i]+1);
    }
    return 0;
}
