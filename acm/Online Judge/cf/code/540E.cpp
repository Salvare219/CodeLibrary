#include<bits/stdc++.h>
using namespace std;


pair<int,int>p[100050];
int sa[600050],f[600050];
long long bit[600050];
long long query(int x)
{
    long long s=0;
    while(x<600005)s+=bit[x],x+=x&-x;
    return s;
}
void updat(int x,long long v)
{
    while(x)bit[x]+=v,x-=x&-x;
}
int inv[600050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,k=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sa[k++]=x;
        sa[k++]=y;
        sa[k++]=x+1;
        sa[k++]=y+1;
        p[i]=make_pair(x,y);
    }
    sort(sa,sa+k);
    k=unique(sa,sa+k)-sa;
    for(int i=0;i<k;i++)
    {
        inv[i]=i;
        if(i==k-1)f[i]=1;
        else f[i]=sa[i+1]-sa[i];
    }
    for(int i=0;i<n;i++)
    {
        int l=lower_bound(sa,sa+k,p[i].first)-sa,r=lower_bound(sa,sa+k,p[i].second)-sa;
        swap(inv[l],inv[r]);
    }
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        ans+=query(inv[i]+1)*f[i];
        updat(inv[i]+1,f[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}

