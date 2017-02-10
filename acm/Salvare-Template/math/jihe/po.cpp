//O(nlognlogn)
struct Point
{
    double x,y;
    bool operator<(Point a)const{return fabs(x-a.x)<1e-8?y<a.y:x<a.x;}
}po[100005],te[100005];
double dis(Point &a,Point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double near_pair(int l,int r)
{
    if(l==r) return 1e10;
    if(l==r-1) return dis(po[l],po[r]);
    int mid=(l+r)>>1,k=0;
    double d=min(near_pair(l,mid),near_pair(mid+1,r));
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
