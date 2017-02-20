#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


struct seg_tree    //i从1开始标
{
    long long dat[200050];
    long long build(int i,int l,int r)
    {
        dat[i]=0;
        if(l<r)build(i<<1,l,l+r>>1),build(i<<1|1,(l+r>>1)+1,r);
    }
    inline void push_down(int i,int l,int r)
    {
        dat[i]+=dat[i>>1];
    }
    inline long long query(int i,int l,int r,int l1)
    {
        if(l==l1 && r==l1) return dat[i];
        else
        {
            int mid=l+r>>1;
            if(dat[i])push_down(i<<1,l,mid),push_down(i<<1|1,mid+1,r),dat[i]=0;
            if(l1>mid)return query(i<<1|1,mid+1,r,l1);
            else return query(i<<1,l,mid,l1);
        }
    }
    inline void updat(int i,int l,int r,int l1,int r1,long long x)
    {
        if(l==l1 && r==r1) dat[i]+=x;
        else
        {
            int mid=l+r>>1;
            if(dat[i])push_down(i<<1,l,mid),push_down(i<<1|1,mid+1,r),dat[i]=0;
            if(l1>mid)updat(i<<1|1,mid+1,r,l1,r1,x);
            else if(r1<=mid)updat(i<<1,l,mid,l1,r1,x);
            else updat(i<<1,l,mid,l1,mid,x),updat(i<<1|1,mid+1,r,mid+1,r1,x);
        }
    }
}g;
int n,m,p;
vector<int>gra[50050];
int hs[50050],fa[50050],top[50050];
int dep[50050],cw[50050],totw;
int dfs(int s,int p)
{
    int y,z=0,f=0,t;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dep[y]=dep[fa[y]=s]+1;
            t=dfs(y,s);
            if(t>z)z=t,f=y;
        }
    hs[s]=f;
}
void build(int s)
{
    int y;
    cw[s]=++totw;
    if(y=hs[s])top[y]=top[s],build(y);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=fa[s]&&y!=hs[s])
            build(top[y]=y);
}
void updat(int x,int y,int z)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(f1,f2),swap(x,y);
        g.updat(1,1,n,cw[f1],cw[x],z);
        x=fa[f1];f1=top[x];
    }
    if(dep[x]<dep[y])swap(x,y);
    g.updat(1,1,n,cw[y],cw[x],z);
}
long long query(int s)
{
    return g.query(1,1,n,s);
}

int w[50050];
int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        int x,y,z;
        for(int i=1;i<=n;i++)
            scanf("%d",w+i),gra[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        g.build(1,1,n);
        dep[1]=1;totw=0;
        dfs(1,0);
        top[1]=1;
        build(1);
        char s[55];
        for(int i=0;i<p;i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d",&x);
                printf("%I64d\n",query(cw[x])+w[x]);
            }
            else
            {
                scanf("%d%d%d",&x,&y,&z);
                if(s[0]=='I')updat(x,y,z);
                else updat(x,y,-z);
            }
        }
    }
    return 0;
}

