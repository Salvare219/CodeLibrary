//#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")

struct tree
{
    int l,r,sum;
}h[2000000];
int rt[100050],tot;
int w[100050];
vector<int>gra[100050];
void insert(int &f,int k,int x)
{
    h[++tot]=h[f];
    h[f=tot].sum++;
    if(k==0)return;
    if(k&x)insert(h[f].r,k>>1,x);
    else insert(h[f].l,k>>1,x);
}
bool check(int a,int b,int c)
{
    int d=c*2-1;
    int e=a&d;
    return (a^e)==b;
}
int query(int x,int y,int z,int k,int p,int d,int st)
{
    if(k==0)return 0;
    int s1=h[h[y].l].sum+h[h[x].l].sum-2*h[h[z].l].sum;
    int s2=h[h[y].r].sum+h[h[x].r].sum-2*h[h[z].r].sum;
    if(check(d,st,k))
    {
        if((d&k)==0)s1++;
        else s2++;
    }
    if(p&k)
    {
        if(s1>0)return k|query(h[x].l,h[y].l,h[z].l,k>>1,p,d,st);
        else query(h[x].r,h[y].r,h[z].r,k>>1,p,d,st|k);
    }
    else
    {
        if(s2>0)return k|query(h[x].r,h[y].r,h[z].r,k>>1,p,d,st|k);
        else query(h[x].l,h[y].l,h[z].l,k>>1,p,d,st);
    }
}
int pre[100050][20];
int dep[100050];
void dfs(int s,int p)
{
    int y;
    rt[s]=rt[p];
    insert(rt[s],1<<15,w[s]);
    pre[s][0]=p;
    for(int i=1;i<20;i++)pre[s][i]=pre[pre[s][i-1]][i-1];
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dep[y]=dep[s]+1;
            dfs(y,s);
        }
}
int lca(int x,int y)
{
    int s=19;
    if(dep[x]>dep[y]) swap(x,y);
    while(dep[x]<dep[y]) y=dep[pre[y][s]]<dep[x]?y:pre[y][s],s--;
    if(x==y) return x;
    else
    {
        s=19;
        while(s!=-1)
        {
            if(pre[x][s]!=pre[y][s])
                x=pre[x][s],y=pre[y][s];
            s--;
        }
        return pre[x][0];
    }
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        for(int i=1;i<=n;i++)
            scanf("%d",w+i),gra[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        rt[0]=tot=0;
        dep[1]=1;
        dfs(1,0);
        for(int i=0;i<m;i++)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            int d=lca(x,y);
            printf("%d\n",query(rt[x],rt[y],rt[d],1<<15,z,w[d],0));
        }
    }
    return 0;
}
