// P0-P1 左侧半平面交  离线 O(nlogn)
//判可行域 用面积比较好
const double pi=acos(-1.0);
struct Line
{
    Point s,t;
    double arg;
    Line(){}
    Line(Point a,Point b){s=a;t=b;arg=atan2(b.y-a.y,b.x-a.x);}
    Point operator&(const Line&a)const{return (t-s)*((s-a.s)*(a.s-a.t))/((s-t)*(a.s-a.t))+s;}
    bool operator<(const Line&a)const
    {
        if(fabs(arg-a.arg)>1e-6)return arg<a.arg;
        else return (a.s-s)*(t-s)>1e-9;
    }
};
int halfplaneintersection(Line v[],int n,Point ans[])
{
    int front=0,tail=0;
    sort(v,v+n);q[0]=v[0];
    for(int i=1;i<n;i++)
        if(fabs(v[i-1].arg-v[i].arg)>1e-6)
        {
            while(front<tail&&(ans[tail-1]-v[i].s)*(v[i].t-v[i].s)>-1e-9)tail--;
            while(front<tail&&(ans[front]-v[i].s)*(v[i].t-v[i].s)>-1e-9)front++;
            if(fabs(q[tail].arg+pi-v[i].arg)<1e-6)return -1;
            ans[tail]=v[i]&q[tail];q[++tail]=v[i];
        }
    while(front<tail&&(ans[tail-1]-q[front].s)*(q[front].t-q[front].s)>-1e-9)tail--;
    ans[tail]=q[tail]&q[front];
    for(int i=front;i<=tail;i++)ans[i-front]=ans[i];
    return tail-front+1;
}


// P1-P2 左侧半平面交  在线 O(n^2)
//k 为半平面的点数 为 0 无解

Point crosspoint(int i,Point p1,Point p2)
{
    double f=xmult(p1-p2,conv[i]-p2);
    f=f/(f-xmult(p1-p2,conv[i+1]-p2));
    return conv[i]+(conv[i+1]-conv[i])*f;
}
void cut(Point p1,Point p2)
{
    int s=0,f;
    conv[k]=conv[0];
    for(int i=0;i<k;i++)
    {
        f=sgn(xmult(p2-p1,conv[i]-p1));
        if(f!=-1) te[s++]=conv[i];
        if(f*sgn(xmult(p2-p1,conv[i+1]-p1))<0) te[s++]=crosspoint(i,p1,p2);
    }
    for(int i=0;i<s;i++) conv[i]=te[i];
    k=s;
}
