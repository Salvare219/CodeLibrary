#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


struct seg_tree
{
    int dat[400050];
    void build(int i,int l,int r)
    {
        if(l<r)build(i<<1,l,l+r>>1),build(i<<1|1,(l+r>>1)+1,r);
        dat[i]=0;
    }
    inline void push_up(int i)
    {
        dat[i]=dat[i<<1]+dat[i<<1|1];
    }
    inline int query(int i,int l,int r,int l1,int r1)
    {
        if(l==l1 && r==r1) return dat[i];
        else
        {
            int mid=l+r>>1;
            if(l1>mid)return query(i<<1|1,mid+1,r,l1,r1);
            else if(r1<=mid)return query(i<<1,l,mid,l1,r1);
            else return query(i<<1,l,mid,l1,mid)+query(i<<1|1,mid+1,r,mid+1,r1);
        }
    }
    inline void updat(int i,int l,int r,int l1,int x)
    {
        if(l==l1 && r==l1) dat[i]=x;
        else
        {
            int mid=l+r>>1;
            if(l1>mid)updat(i<<1|1,mid+1,r,l1,x);
            else updat(i<<1,l,mid,l1,x);
            push_up(i);
        }
    }
}g;
struct edge
{
    int y,id,next;
}e[200050];
int head[100050];
int how[100050];
int hs[100050],fa[100050],top[100050];
int dep[100050],cw[100050],totw;
int pos[100050];
int dfs(int s)
{
    int y,z=0,f=0,t,sum=1;
    for(int i=head[s];~i;i=e[i].next)
        if((y=e[i].y)!=fa[s])
        {
            pos[e[i].id]=y;
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
int n,q,s;
void updat(int x,int z)
{
    g.updat(1,1,n,cw[x],z);
}
int query(int x,int y)
{
    int f1=top[x],f2=top[y];
    int sum=0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(f1,f2),swap(x,y);
        sum+=g.query(1,1,n,cw[f1],cw[x]);
        x=fa[f1];f1=top[x];
    }
    if(x==y)return sum;
    if(dep[x]<dep[y])swap(x,y);
    return sum+g.query(1,1,n,cw[hs[y]],cw[x]);
}
int mm;
void add(int x,int y,int id)
{
    e[mm].y=y;
    e[mm].id=id;
    e[mm].next=head[x];
    head[x]=mm++;
    e[mm].y=x;
    e[mm].id=id;
    e[mm].next=head[y];
    head[y]=mm++;
}
int main()
{
    while(~scanf("%d%d%d",&n,&q,&s))
    {
        int x,y,z;
        for(int i=1;i<=n;i++)
            head[i]=-1;mm=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,i);
            how[i]=z;
        }
        dep[1]=1;totw=0;
        dfs(1);
        top[1]=1;
        build(1);
        g.build(1,1,n);
        for(int i=1;i<n;i++)
            g.updat(1,1,n,cw[pos[i]],how[i]);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&x);
            if(!x)
            {
                scanf("%d",&y);
                printf("%d\n",query(s,y));
                s=y;
            }
            else
            {
                scanf("%d%d",&y,&z);
                updat(pos[y],z);
            }
        }
    }
    return 0;
}

