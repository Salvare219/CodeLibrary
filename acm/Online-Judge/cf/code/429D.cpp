#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    long long x,y;
    bool operator<(Point a)const{return x==a.x?y<a.y:x<a.x;}
}po[100005],te[100005];
long long dis(Point &a,Point &b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
long long near_pair(int l,int r)
{
    if(l==r) return 1e10;
    if(l==r-1) return dis(po[l],po[r]);
    int mid=(l+r)>>1,k=0;
    long long d=min(near_pair(l,mid),near_pair(mid+1,r));
    for(int i=mid;i>=l && po[mid].x-po[i].x<d;i--)
        te[k].x=po[i].y,te[k++].y=po[i].x;
    for(int i=mid+1;i<=r && po[i].x-po[mid].x<d;i++)
        te[k].x=po[i].y,te[k++].y=po[i].x;
    sort(te,te+k);
    for(int i=0;i<k;i++)
        for(int j=1;j<5 && i+j<k;j++)
            d=min(d,dis(te[i],te[i+j]));
    return d;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
        po[i].x=i;
        po[i].y=sum;
    }
    printf("%I64d\n",near_pair(1,n));
    return 0;
}
