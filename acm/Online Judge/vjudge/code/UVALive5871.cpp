#include<bits/stdc++.h>
using namespace std;


struct p
{
    char s[3];
    int x,y;
}q[500050];
int sa[500050];
pair<int,int>px[500050];
pair<int,pair<int,int> >qx[500050];
int bit[500050];
inline int query(int x)
{
    int s=0;
    while(x<500005)s+=bit[x],x+=x&-x;
    return s;
}
inline void updat(int x)
{
    while(x)bit[x]++,x-=x&-x;
}
inline void clr(int x)
{
    while(x)bit[x]=0,x-=x&-x;
}
vector<int>c;
int ans[500050];
void solv(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    solv(l,mid);solv(mid+1,r);
    int k=0,f=0;
    for(int i=l;i<=mid;i++)
        if(q[i].s[0]=='+')
        {
            sa[k++]=q[i].y;
            px[f++]=make_pair(q[i].x,q[i].y);
        }
    int z=0;
    for(int i=mid+1;i<=r;i++)
        if(q[i].s[0]=='?')
            qx[z++]=make_pair(q[i].x,make_pair(q[i].y,i));
    sort(sa,sa+k);
    k=unique(sa,sa+k)-sa;
    sort(px,px+f);sort(qx,qx+z);
    int p=0,h;c.clear();
    for(int i=0;i<z;i++)
    {
        while(p<f&&px[p].first<=qx[i].first)
        {
            h=lower_bound(sa,sa+k,px[p].second)-sa+1;
            c.push_back(h);
            updat(h);
            p++;
        }
        h=lower_bound(sa,sa+k,qx[i].second.first)-sa+1;
        ans[qx[i].second.second]+=query(h);
    }
    for(int i=0;i<c.size();i++)
        clr(c[i]);
}
int main()
{
    int m;scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%s%d%d",q[i].s,&q[i].x,&q[i].y);
    solv(0,m-1);
    for(int i=0;i<m;i++)
        if(q[i].s[0]=='?')
            printf("%d\n",ans[i]);
    return 0;
}
