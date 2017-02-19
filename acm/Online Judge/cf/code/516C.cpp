#include <bits/stdc++.h>

using namespace std;

long long h[200010],dist[200010],maxx1[800010],maxx2[800010],tree[800010],d[100010];

struct node
{
    long long maxx1,maxx2,num;
};

void build(int l,int r,int pos)
{
    if(l==r)
    {
        maxx1[pos]=2*h[l]-dist[l];
        maxx2[pos]=2*h[l]+dist[l];
        tree[pos]=0;
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,pos*2);
    build(mid+1,r,pos*2+1);
    tree[pos]=max(tree[pos*2],tree[pos*2+1]);
    tree[pos]=max(maxx1[pos*2]+maxx2[pos*2+1],tree[pos]);
    maxx1[pos]=max(maxx1[pos*2],maxx1[pos*2+1]);
    maxx2[pos]=max(maxx2[pos*2],maxx2[pos*2+1]);
}

node query(int l,int r,int x,int y,int pos)
{
    if(l>=x&&r<=y)
    {
        node res;
        res.num=tree[pos];
        res.maxx1=maxx1[pos];
        res.maxx2=maxx2[pos];
        return res;
    }
    int mid=(l+r)/2;
    if(y<=mid)
        return query(l,mid,x,y,pos*2);
    else if(x>mid)
        return query(mid+1,r,x,y,pos*2+1);
    else
    {
        node res,temp1,temp2;
        temp1=query(l,mid,x,y,pos*2);
        temp2=query(mid+1,r,x,y,pos*2+1);
        res.num=max(temp1.num,temp2.num);
        res.num=max(res.num,temp1.maxx1+temp2.maxx2);
        res.maxx1=max(temp1.maxx1,temp2.maxx1);
        res.maxx2=max(temp1.maxx2,temp2.maxx2);
        return res;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&d[i]);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&h[i]);
    dist[1]=0;
    for(int i=2;i<=n;i++)
        dist[i]=dist[i-1]+d[i-1];
    dist[n+1]=dist[n]+d[n];
    for(int i=n+2;i<2*n;i++)
        dist[i]=dist[i-1]+d[i-n-1];
    for(int i=1;i<=n;i++)
        h[i+n]=h[i];
    build(1,2*n-1,1);
    int l,r;
    node res;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        if(l<=r)
        {
            res=query(1,2*n-1,r+1,n+l-1,1);
            printf("%I64d\n",res.num);
        }
        else
        {
            res=query(1,2*n-1,r+1,l-1,1);
            printf("%I64d\n",res.num);
        }
    }
    return 0;
}
