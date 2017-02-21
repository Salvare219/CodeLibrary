#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


struct p
{
    int x,y,g,i;
    bool operator<(const p&a)const
    {
        return g==a.g?y<a.y:g<a.g;
    }
}q[50050];
int a[50050];
int cnt[50050];
long long ans[50050][2];
long long x,y;
void ins(int xx,int ff)
{
    long long z=cnt[xx];
    cnt[xx]+=ff;
    long long z1=cnt[xx];
    x=x-z*(z-1)/2+z1*(z1-1)/2;
}
void updat(int l,int l1,int r,int r1)
{
    int f;
    f=1;
    if(r>r1)swap(r,r1),f=-1;
    for(int i=r1;i>r;i--)
        ins(a[i],f);
    f=-1;
    if(l>l1)swap(l,l1),f=1;
    for(int i=l;i<l1;i++)
        ins(a[i],f);
}
long long gcd(long long x,long long y)
{
    while(x&&y)x>y?x%=y:y%=x;
    return x+y;
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d%d",&q[i].x,&q[i].y),q[i].g=q[i].x/250,q[i].i=i;
    sort(q,q+m);
    int l=1,r=0;
    x=y=0;
    for(int i=0;i<m;i++)
    {
        updat(l,q[i].x,r,q[i].y);
        l=q[i].x;r=q[i].y;
        y=r-l+1;
        long long z=y*(y-1)/2;
        long long zz=gcd(x,z);
        ans[q[i].i][0]=x/zz;
        ans[q[i].i][1]=z/zz;
    }
    for(int i=0;i<m;i++)
        printf("%lld/%lld\n",ans[i][0],ans[i][1]);
    return 0;
}
