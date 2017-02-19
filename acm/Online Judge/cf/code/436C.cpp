#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int x,y,w;
    p(){}
    p(int x_,int y_,int w_){x=x_;y=y_;w=w_;}
    bool operator<(const p&a)const
    {return w<a.w;}
}e[2000050];
int n,m,k,w,cnt;
int com[20005];
int findd(int s)
{
    return com[s]==s?s:com[s]=findd(com[s]);
}
char maz[2005][20][20];
int dif(int x,int y)
{
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(maz[x][i][j]!=maz[y][i][j])cnt++;
    return cnt*w;
}
vector<int>gra[2005];
void dfs(int s,int p)
{
    if(p!=-1)printf("%d %d\n",s,p);
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            dfs(gra[s][i],s);
        }
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int i=0;i<=k;i++)com[i]=i;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%s",maz[i][j]);
    }
    for(int i=1;i<=k;i++)
        e[cnt++]=p(0,i,n*m);
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
            if(i!=j)
            {
                e[cnt++]=p(i,j,dif(i,j));
            }
    }
    sort(e,e+cnt);
    int f=0,ans=0,z=0,x,y;
    for(int i=0;i<k;i++)
    {
        do
        {
            x=e[f].x;
            y=e[f].y;
            w=e[f++].w;
            if(findd(x)!=findd(y))
            {
                com[findd(x)]=findd(y);
                gra[x].push_back(y);
                gra[y].push_back(x);
                ans+=w;break;
            }
        }while(1);
    }
    printf("%d\n",ans);
    dfs(0,-1);
    return 0;
}
