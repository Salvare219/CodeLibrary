#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int ty[500000];
bool del[500000];
int deg[500000];
vector<int> gra[500000];
int dfs(int s)
{
    int ss=0,t=0,f=0;
    for(int i=0;i<gra[s].size();i++)
        if(del[gra[s][i]]==0)
        {
            ss=dfs(gra[s][i])+1;
            if(ss>t) t=ss;
        }
    return t;
}
int dfs2(int s)
{
    int ss=0,t=0,f=0;
    for(int i=0;i<gra[s].size();i++)
        if(del[gra[s][i]]==0)
        {
            ss=dfs2(gra[s][i])+1;
            if(ss>t) t=ss,f=gra[s][i];
        }
    if(t==0) ;
    else printf("%d ",f);
    return t;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",ty+i);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x) gra[i+1].push_back(x),deg[x]++;
    }
    int ans=0,fl=0;
    for(int i=1;i<=n;i++)
        if(deg[i]>1) del[i]=1;
    for(int i=1;i<=n;i++)
        if(ty[i])
        {
            x=dfs(i);
            if(x+1>ans) ans=x+1,fl=i;
        }
    printf("%d\n",ans);
    dfs2(fl);printf("%d\n",fl);
    return 0;
}


