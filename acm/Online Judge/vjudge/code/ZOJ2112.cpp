#include <bits/stdc++.h>
using namespace std;


struct tree
{
    int l,r,sum;
}h[2000000];
int rt[50050],tot;
void insert(int &f,int l,int r,int x,int v)
{
    h[++tot]=h[f];
    h[f=tot].sum+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x>mid)insert(h[f].r,mid+1,r,x,v);
    else insert(h[f].l,l,mid,x,v);
}
int n,m,k;
int bit[50050];
int cx[200],cy[200];
int query(int x,int y,int l,int r,int k)
{
    int mid,s;
    int kx=0,ky=0;
    for(int i=x;i;i-=i&-i)cx[kx++]=bit[i];
    for(int i=y;i;i-=i&-i)cy[ky++]=bit[i];
    x=rt[x];y=rt[y];
    while(r>l)
    {
        mid=(l+r)>>1;
        s=h[h[y].l].sum-h[h[x].l].sum;
        for(int i=0;i<kx;i++)s-=h[h[cx[i]].l].sum;
        for(int i=0;i<ky;i++)s+=h[h[cy[i]].l].sum;
        if(s<k)
        {
            y=h[y].r;x=h[x].r;
            for(int i=0;i<kx;i++)cx[i]=h[cx[i]].r;
            for(int i=0;i<ky;i++)cy[i]=h[cy[i]].r;
            l=mid+1;
            k-=s;
        }
        else
        {
            y=h[y].l;x=h[x].l;
            for(int i=0;i<kx;i++)cx[i]=h[cx[i]].l;
            for(int i=0;i<ky;i++)cy[i]=h[cy[i]].l;
            r=mid;
        }
    }
    return l;
}
int a[50050],sa[60050];
struct p
{
    int l,r,k,ty;
}q[10050];
inline int get(int x)
{
    return lower_bound(sa,sa+k,x)-sa;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        k=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i),sa[k++]=a[i];
        char s[5];
        for(int i=0;i<m;i++)
        {
            scanf("%s",s);
            if(s[0]=='Q')
                scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k),q[i].ty=0;
            else
                scanf("%d%d",&q[i].l,&q[i].r),q[i].ty=1,sa[k++]=q[i].r;
        }
        sort(sa,sa+k);tot=0;
        k=unique(sa,sa+k)-sa;
        for(int i=1;i<=n;i++)
        {
            rt[i]=rt[i-1];bit[i]=0;
            insert(rt[i],0,k-1,get(a[i-1]),1);
        }
        for(int i=0;i<m;i++)
            if(q[i].ty)
            {
                int l=q[i].l,r=get(a[q[i].l-1]),f=get(q[i].r);
                while(l<=n)
                {
                    insert(bit[l],0,k-1,r,-1);
                    insert(bit[l],0,k-1,f,1);
                    l+=l&-l;
                }
                a[q[i].l-1]=q[i].r;
            }
            else
                printf("%d\n",sa[query(q[i].l-1,q[i].r,0,k-1,q[i].k)]);
    }
    return 0;
}
