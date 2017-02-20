#include <bits/stdc++.h>
using namespace std;



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
int lef[100050],rig[100050];
int find(int c[],int p)
{
    return c[p]==p?p:c[p]=find(c,c[p]);
}
int cnt;
pair<int,int>p[100050];
int n,m;
int bit[100050];
int a[100050];
int query1(int x)
{
    int s=0;
    while(x<=n)s+=bit[x],x+=x&-x;
    return s;
}
void updat1(int x,int v)
{
    while(x)bit[x]+=v,x-=x&-x;
}
int updat(int x)
{
    if(a[x]>1)return a[x]--,cnt;
    else
    {
        a[x]=0;
        lef[x]=x-1;
        rig[x]=x+1;
        int l=find(lef,x),r=find(rig,x),mid,f=0;
        l++;r--;
        int y=rt[lower_bound(p,p+m,make_pair(l,-1))-p];
        int z=rt[upper_bound(p,p+m,make_pair(r,n+50))-p];
        int k1=l,k2=r;
        l=1;r=n+1;
        while(r>l)
        {
            mid=(r+l)>>1;
            if(mid<=k2)
            {
                l=mid+1;
                f+=h[h[z].l].sum-h[h[y].l].sum;
                z=h[z].r;y=h[y].r;
            }
            else
            {
                r=mid;
                z=h[z].l;y=h[y].l;
            }
        }
        int s=query1(k1)-query1(k2+1);
        updat1(k1,f-s);
        return cnt+=f-s;
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i),lef[i]=rig[i]=i,bit[i]=0;
        rig[n+1]=n+1;
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),p[i]=make_pair(x,y);
        sort(p,p+m);tot=0;
        for(int i=1;i<=m;i++)
        {
            rt[i]=rt[i-1];
            insert(rt[i],1,n+1,p[i-1].second);
        }
        int q,las=0;
        cnt=0;scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&x);
            //printf("****%d\n",x+las);
            printf("%d\n",las=updat(x+las));
        }
    }
    return 0;
}
