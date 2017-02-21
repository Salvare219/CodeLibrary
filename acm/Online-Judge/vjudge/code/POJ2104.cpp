#include<cstdio>
#include<algorithm>
using namespace std;



//编号从1开始
struct tree
{
    int l,r,sum;
}h[2000000];
int rt[100050],tot;
void insert(int &f,int l,int r,int x)
{
    h[++tot]=h[f];
    h[f=tot].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(x>mid)insert(h[f].r,mid+1,r,x);
    else insert(h[f].l,l,mid,x);
}
int query(int x,int y,int l,int r,int k)
{
    int mid,s;
    while(r>l)
    {
        s=h[h[y].l].sum-h[h[x].l].sum;mid=(l+r)>>1;
        if(s<k)x=h[x].r,y=h[y].r,l=mid+1,k-=s;
        else x=h[x].l,y=h[y].l,r=mid;
    }
    return l;
}
int a[100050],sa[100050];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i),sa[i]=a[i];
        sort(sa,sa+n);
        int k=unique(sa,sa+n)-sa;
        for(int i=0;i<n;i++)
            a[i]=lower_bound(sa,sa+k,a[i])-sa+1;
        rt[0]=tot=0;
        for(int i=1;i<=n;i++)
        {
            rt[i]=rt[i-1];
            insert(rt[i],1,k,a[i-1]);
        }
        for(int i=0;i<m;i++)
        {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",sa[query(rt[x-1],rt[y],1,k,z)-1]);
        }
    }
    return 0;
}
