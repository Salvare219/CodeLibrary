#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,k;
vector<int>gra[200050];
int dep[200050];
int col[200050][2];
void dfs(int s,int p)
{
    col[s][0]=k++;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)dep[gra[s][i]]=dep[s]+1,dfs(gra[s][i],s);
    col[s][1]=k;
}
int bit[400050];
void updat(int x,int v)
{
    while(x<=k) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x) s+=bit[x],x-=x&-x;
    return s;
}
int a[200050];
int main()
{
 //   freopen("1.txt","r",stdin);
    int x,y;k=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<n;i++)
        scanf("%d%d",&x,&y),gra[x].push_back(y),gra[y].push_back(x);
    dep[1]=1;dfs(1,0);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d%d",&x,&y);
            if(dep[x]&1) ;
            else y=-y;
            updat(col[x][0],y);
            updat(col[x][1],-y);
        }
        else
        {
            scanf("%d",&x);
            if(dep[x]&1)printf("%d\n",a[x]+query(col[x][0]));
            else printf("%d\n",a[x]-query(col[x][0]));
        }
    }
    return 0;
}

