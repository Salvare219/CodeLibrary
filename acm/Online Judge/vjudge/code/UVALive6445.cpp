#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


bool lin[2005][2005];
vector<int> gra[4005];
bool vis[4005];
int stack[4005],sk;
int low[4005],scc[4005];
int timer,cnt;
void tarjan(int s)
{
    vis[s]=1;
    int to,temp=low[s]=++timer;
    stack[sk++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(vis[to]==0) tarjan(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--sk];
            low[to]=0x3fffffff;
            scc[to]=cnt;
        }while(stack[sk]!=s);
        cnt++;
    }
}
int col[4005];
int ans1[4005];
int ans2[4005];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        for(int i=1;i<=2*n;i++)
        {
            gra[i].clear();
            vis[i]=0;
            col[i]=0;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                lin[i][j]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            lin[x][y]=1;
            lin[y][x]=1;
        }
        col[1]=1;col[2]=2;
        for(int j=1;j<=n;j++)
            if(lin[1][j])
                col[j]=1;
        for(int j=1;j<=n;j++)
            if(lin[2][j])
                col[j]=2;
        gra[1+n].push_back(1);
        gra[2+n].push_back(2);
        int f=0;
        for(int i=3;i<=n;i++)
            if(col[i]==0)
            {
                gra[i].push_back(i+n);
                for(int j=i+1;j<=n;j++)
                    if(lin[i][j]==0)
                    {
                        if(col[j]==0)
                            f=1;
                        else
                            gra[j+n].push_back(j);
                    }
            }
            else
            {
                for(int j=i+1;j<=n;j++)
                    if(lin[i][j]==0)
                    {
                        if(col[i]==col[j])
                        {
                            gra[i].push_back(j+n);
                            gra[j].push_back(i+n);
                        }
                        else if(col[j]==0)
                            gra[i+n].push_back(i);
                        gra[i+n].push_back(j);
                        gra[j+n].push_back(i);
                    }
            }
        if(f)puts("impossible");
        else
        {
            cnt=1;timer=0;
            for(int i=1;i<=2*n;i++)
                if(vis[i]==0)
                    tarjan(i);
            int k1=0,k2=0;
            f=0;
            for(int i=1;i<=n;i++)
                if(scc[i]==scc[i+n])
                {
                    f=1;
                    break;
                }
                else if(scc[i]<scc[i+n])
                {
                    if(col[i]==1)
                        ans1[k1++]=i;
                    else
                        ans2[k2++]=i;
                }
            if(f)puts("impossible");
            else
            {
                for(int i=0;i<k1;i++)
                    printf("%d%c",ans1[i],i==k1-1?10:32);
                for(int i=0;i<k2;i++)
                    printf("%d%c",ans2[i],i==k2-1?10:32);
            }
        }
    }
    return 0;
}