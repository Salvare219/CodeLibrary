#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    double x,y;
    bool ty;
    bool operator<(Point a)const{return abs(x-a.x)<1e-8?y<a.y:x<a.x;}
}po[200005],te[200005];
double dis(Point &a,Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double near_pair(int l,int r)
{
    if(l==r) return 1e10;
    if(l==r-1)
    {
        if(po[l].ty^po[r].ty)return dis(po[l],po[r]);
        else return 1e10;
    }
    int mid=(l+r)>>1,k=0;
    double d=min(near_pair(l,mid),near_pair(mid+1,r));
    for(int i=mid;i>=l && po[mid].x-po[i].x<d;i--)
        te[k].x=po[i].y,te[k].y=po[i].x,te[k++].ty=po[i].ty;
    for(int i=mid+1;i<=r && po[i].x-po[mid].x<d;i++)
        te[k].x=po[i].y,te[k].y=po[i].x,te[k++].ty=po[i].ty;
    sort(te,te+k);
    for(int i=0;i<k;i++)
        for(int j=1;j<5 && i+j<k;j++)
            if(te[i].ty^te[i+j].ty)d=min(d,dis(te[i],te[i+j]));
    return d;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lf%lf",&po[i].x,&po[i].y),po[i].ty=0;
        for(int i=2*n-1;i>=n;i--)scanf("%lf%lf",&po[i].x,&po[i].y),po[i].ty=1;
        sort(po,po+2*n);
        printf("%.3f\n",near_pair(0,2*n-1));
    }
    return 0;
}