#include <bits/stdc++.h>
using namespace std;


struct p
{
    int l,r,g,i;
    bool operator<(const p&a)const
    {
        return g==a.g?r<a.r:g<a.g;
    }
}q[200050];
int ans[200050],cnt;
int v[1000050];
int a[30050];
inline void cg(int x,int y)
{
    if(y==1)
    {
        if(v[x]==0)cnt++;
        v[x]++;
    }
    else
    {
        if(v[x]==1)cnt--;
        v[x]--;
    }
}
int updat(int l,int r,int x,int y)
{
    int d=-1;
    if(l>x)swap(l,x),d=1;
    for(int i=l;i<x;i++)cg(a[i],d);
    d=1;
    if(r>y)swap(r,y),d=-1;
    for(int i=y;i>r;i--)cg(a[i],d);
    return cnt;
}
int main()
{
    int n,m;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].i=i,q[i].g=q[i].l/170;
    sort(q,q+m);
    int l=0,r=0;cnt=0;
    for(int i=0;i<m;i++)
        ans[q[i].i]=updat(l,r,q[i].l,q[i].r),l=q[i].l,r=q[i].r;
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
