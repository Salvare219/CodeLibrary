//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")


struct edge
{
    int y,next;
    edge(){}
    edge(int _y,int _next){y=_y;next=_next;}
}e[200050];
int head[100050],mm;
void add(int x,int y)
{
    e[mm]=edge(y,head[x]);head[x]=mm++;
    e[mm]=edge(x,head[y]);head[y]=mm++;
}
int hs[100050],fa[100050],top[100050];
int dep[100050],cw[100050],totw;
int dfs(int s)
{
    int y,z=0,f=0,t,sum=1;
    for(int i=head[s];~i;i=e[i].next)
        if((y=e[i].y)!=fa[s])
        {
            dep[y]=dep[fa[y]=s]+1;
            t=dfs(y);sum+=t;
            if(t>z)z=t,f=y;
        }
    return hs[s]=f,sum;
}
void build(int s)
{
    int y;
    cw[s]=++totw;
    if(y=hs[s])top[y]=top[s],build(y);
    for(int i=head[s];~i;i=e[i].next)
        if((y=e[i].y)!=fa[s]&&y!=hs[s])
            build(top[y]=y);
}
vector<int>col[100050];
void updat(int x,int y,int z)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(f1,f2),swap(x,y);
        col[cw[f1]].push_back(z);
        col[cw[x]+1].push_back(-z);
        x=fa[f1];f1=top[x];
    }
    if(dep[x]<dep[y])swap(x,y);
    col[cw[y]].push_back(z);
    col[cw[x]+1].push_back(-z);
}
int dat[400050],ans[400050];
void build(int i,int l,int r)
{
    int mid=l+r>>1;
    if(l==r)ans[i]=l;
    else build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}
void push_up(int i)
{
    if(dat[i<<1]<dat[i<<1|1])dat[i]=dat[i<<1|1],ans[i]=ans[i<<1|1];
    else dat[i]=dat[i<<1],ans[i]=ans[i<<1];
}
void updat(int i,int l,int r,int x,int f)
{
    if(l==x&&r==x)
        dat[i]+=f;
    else
    {
        int mid=l+r>>1;
        if(x>mid)updat(i<<1|1,mid+1,r,x,f);
        else updat(i<<1,l,mid,x,f);
        push_up(i);
    }
}
int fin[100050],who[100050];
int main()
{
    int n,m;
    build(1,1,100000);
    while(scanf("%d%d",&n,&m)&&n)
    {
        int x,y,z;mm=0;
        for(int i=1;i<=n+1;i++)head[i]=-1,col[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d",&x,&y),add(x,y);
        dep[1]=1;totw=0;
        dfs(1);top[1]=1;
        build(1);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&x,&y,&z),updat(x,y,z);
        for(int i=1;i<=n;i++)
            who[cw[i]]=i;
        int ty=0,k=0;
        for(int i=1;i<=n+1;i++)
        {
            int sz=col[i].size();
            for(int j=0;j<sz;j++)
                if(col[i][j]>0)
                    updat(1,1,100000,col[i][j],1);
                else
                    updat(1,1,100000,-col[i][j],-1);
            if(i<=n)
            {
                if(dat[1]==0)fin[who[i]]=0;
                else fin[who[i]]=ans[1];
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d\n",fin[i]);
    }
    return 0;
}
