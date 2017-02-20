#include <bits/stdc++.h>
using namespace std;



struct tree
{
    int l,r,sum;
}h[2000000];
int rt[100050],tot;
void insert(int &f,int l,int r,int x)
{
    h[++tot]=h[f];f=tot;
    h[f].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x>mid)insert(h[f].r,mid+1,r,x);
    else insert(h[f].l,l,mid,x);
}
vector<int>gra[100050];
int pre[100050][20];
int dep[100050];
int w[100050];
int sa[100050],k;
void dfs(int s,int p)
{
    int y;
    pre[s][0]=p;
    rt[s]=rt[p];
    insert(rt[s],0,k-1,w[s]);
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
int query(int x,int y,int f)
{
    int e=lca(x,y);
    //printf("%d %d %d\n",x,y,d);
    int l=0,r=k-1,mid;
    int a=rt[x],b=rt[y],c=rt[e],d=rt[pre[e][0]];
    while(l<r)
    {
        mid=(l+r)>>1;
        int s=h[h[a].l].sum+h[h[b].l].sum-h[h[c].l].sum-h[h[d].l].sum;
        if(s>=f)
        {
            r=mid;
            a=h[a].l;
            b=h[b].l;
            c=h[c].l;
            d=h[d].l;
        }
        else
        {
            l=mid+1;
            a=h[a].r;
            b=h[b].r;
            c=h[c].r;
            d=h[d].r;
            f-=s;
        }
    }
    return l;
}
int main()
{
    int n,m,x,y,z;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i),sa[i-1]=w[i];
    sort(sa,sa+n);
    k=unique(sa,sa+n)-sa;
    for(int i=1;i<=n;i++)
        w[i]=lower_bound(sa,sa+k,w[i])-sa;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    dep[1]=1;tot=0;
    dfs(1,0);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",sa[query(x,y,z)]);
    }
    return 0;
}