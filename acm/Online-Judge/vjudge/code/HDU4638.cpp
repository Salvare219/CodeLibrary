#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


struct p
{
    int x,y,g,i;
    p(){}
    p(int x_,int y_,int g_,int i_){x=x_;y=y_;g=g_;i=i_;}
    bool operator<(const p&a)const
    {return g==a.g?y<a.y:g<a.g;}
}q[100050];
int a[100050];
bool v[100050];
int ans[100050];
int C(int x)
{
    int c=a[x];
    v[c]^=1;
    if(v[c-1]==v[c+1])
    {
        if(v[c]==v[c-1])
            return -1;
        else
            return 1;
    }
    else return 0;
}
int updat(int l,int x,int r,int y)
{
    int sum=0;
    if(l>x)swap(l,x);
    for(int i=l;i<x;i++)
        sum+=C(i);
    if(r>y)swap(r,y);
    for(int i=r+1;i<=y;i++)
        sum+=C(i);
    return sum;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y,z;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i),v[i+1]=0;
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),q[i]=p(x-1,y-1,(x-1)/300,i);
        sort(q,q+m);
        int l=0,r=0,tot=1;
        v[a[0]]=1;
        for(int i=0;i<m;i++)
        {
            tot+=updat(l,q[i].x,r,q[i].y);
            ans[q[i].i]=tot;
            l=q[i].x;r=q[i].y;
        }
        for(int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
