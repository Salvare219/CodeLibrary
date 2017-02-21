#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<int>gra[205];
int p[205];
bool v[205];
int ch[205];
int find(int s,int f)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if(v[y=gra[s][i]]==0&&ch[y]==0)
        {
            v[y]=1;
            if(p[y]==0||find(p[y],f))
            {
                f?p[y]=s,p[s]=y:0;
                return 1;
            }
        }
    return 0;
}
int fi[205];
int col[205];
int lin[205][205];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",col+i),gra[i].clear();

        memset(lin,0,sizeof(lin));

        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x++;y++;
            if(x==y)continue;
            if(lin[x][y])continue;
            if(col[x]!=col[y])
            {
                lin[x][y]=lin[y][x]=1;
                gra[y].push_back(x);
                gra[x].push_back(y);
            }
            //printf("%d %d\n",x,y);
        }
        int ans=0;
        memset(p,0,sizeof(p));
        memset(ch,0,sizeof(ch));
        for(int i=1;i<=n;i++)
            if(p[i]==0)
            {
                memset(v,0,sizeof(v));
                ans+=find(i,1);
            }
        for(int i=1;i<=n;i++)
            if(p[i])
            {
                    memset(v,0,sizeof(v));
                    int a=p[i],b=p[p[i]];
                    ch[i]=1;
                    p[p[i]]=0;
                    p[i]=0;
                    if(find(a,0))
                        ch[i]=0,p[i]=a,p[p[i]]=b;
            }
        int k=0;
        printf("%d",ans);
        for(int i=1;i<=n;i++)
            if(ch[i])printf(" %d",i-1);
        putchar(10);
    }
    return 0;
}
