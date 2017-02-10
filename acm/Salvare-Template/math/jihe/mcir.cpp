//两圆交点   返回 0 无解
bool cir_cross(Point p1,double r1,Point p2,double r2,Point ans[])
{
    double d=p1/p2,cosa,sina;
    if(sgn(d-r1-r2)==1||sgn(fabs(r1-r2)-d)==1)return 0;
    cosa=(r1*r1+d*d-r2*r2)/(2*r1*d);
    sina=sqrt(max(0.0,1.0-cosa*cosa));
    Point ve=(p2-p1)*r1/d;
    ans[0]=p1+Point(ve.x*cosa+ve.y*sina,ve.y*cosa-ve.x*sina);
    ans[1]=p1+Point(ve.x*cosa-ve.y*sina,ve.y*cosa+ve.x*sina);
    return 1;
}

//两圆面积交  两圆面积并可以减这个实现
double cir_inter(Point a,double ra,Point b,double rb)
{
    double d=a/b;
    if(ra>rb)swap(ra,rb);
    if(sgn(ra+rb-d)!=1)return 0.0;
    if(sgn(d+ra-rb)!=1)return pi*ra*ra;
    double p1=2*acos((ra*ra+d*d-rb*rb)/(2.0*ra*d));
    double p2=2*acos((rb*rb+d*d-ra*ra)/(2.0*rb*d));
    return ((p1-sin(p1))*ra*ra+(p2-sin(p2))*rb*rb)*0.5;
}

//圆与圆心三角形面积交
double cir_tri(Point c,double r,Point p1,Point p2)
{
    bool f=1;p1=p1-c;p2=p2-c;
    double sum=p1*p2,h,r1,r2,r3;
    if(sgn(sum)==0)return 0.0;
    if(sgn(sum)==-1)swap(p1,p2),f=0;
    r2=p1/Point(0,0);r3=p2/Point(0,0);r1=(p1%p2)/(r2*r3);
    Point v,s=p2-p1,t1=Point(-s.y,s.x),t2=t1*(p1*(p2-p1))/(t1*(p2-p1));
    v=s/(p1/p2);h=t2.x*t2.x+t2.y*t2.y;
    if(sgn(r*r-h)!=1)sum=acos(r1)*r*r;
    else
    {
        int d1,d2;h=sqrt(r*r-h);
        t1=t2-v*h;t2=t2+v*h;
        r2=(p1%t1)/((t1/Point(0,0))*r2);
        r3=(p2%t2)/((t2/Point(0,0))*r3);
        d1=sgn(p1*t2)==1?sgn(p1*t1)==1:-1;
        d2=sgn(p2*t2)==1?sgn(p2*t1)==1:-1;
        if(d1*d2==1)sum=acos(r1)*r*r;
        else if(d1*d2==-1)sum=acos(r2)*r*r+acos(r3)*r*r+t1*t2;
        else if(d1!=0)sum=acos(r2)*r*r+t1*p2;
        else if(d2!=0)sum=p1*t2+acos(r3)*r*r;
        else sum=p1*p2;
    }
    return (f?sum:-sum)*0.5;
}

//单位圆最大点覆盖
const double pi=acos(-1.0);
pair<double,bool>arg[605];
int cir_point(Point po[],int n,double r)
{
    double d,th,dth,p1,p2;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0,k=0,tot=0;
        for(int j=0;j<n;j++)
            if(i!=j&&sgn((d=po[i]/po[j])-r-r)==-1)
            {
                dth=acos(d*0.5/r);
                th=atan2(po[j].y-po[i].y,po[j].x-po[i].x);
                p1=th-dth;p2=th+dth;
                if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                arg[k++]=make_pair(p1,0);arg[k++]=make_pair(p2,1);
            }
        sort(arg,arg+k);
        for(int j=0;j<k;j++)
            if(arg[j].second)cnt--;
            else tot=max(tot,++cnt);
        ans=max(tot+1,ans);
    }
    return ans;
}

//多圆面积并
const double eps = 1e-7;
const double pi=acos(-1.0);
pair<double,bool>arg[2005];
double cir_union(Point c[],double r[],int n)
{
    double sum=0.0,sum1=0.0,d,p1,p2,p3;
    for(int i=0;i<n;i++)
    {
        bool f=1;
        for(int j=0;f&&j<n;j++)
            if(i!=j&&sgn(r[j]-r[i]-c[i]/c[j])!=-1)f=0;
        if(!f)swap(r[i],r[--n]),swap(c[i--],c[n]);
    }
    for(int i=0;i<n;i++)
    {
        int k=0,cnt=0;
        for(int j=0;j<n;j++)
            if(i!=j&&sgn((d=c[i]/c[j])-r[i]-r[j])<=0)
            {
                p3=acos((r[i]*r[i]+d*d-r[j]*r[j])/(2.0*r[i]*d));
                p2=atan2(c[j].y-c[i].y,c[j].x-c[i].x);
                p1=p2-p3;p2=p2+p3;
                if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                arg[k++]=make_pair(p1,0);arg[k++]=make_pair(p2,1);
            }
        if(k)
        {
            sort(arg,arg+k);
            p1=arg[k-1].first-2*pi;
            p3=r[i]*r[i];
            for(int j=0;j<k;j++)
            {
                p2=arg[j].first;
                if(cnt==0)
                {
                    sum+=(p2-p1-sin(p2-p1))*p3;
                    sum1+=(c[i]+Point(cos(p1),sin(p1))*r[i])*(c[i]+Point(cos(p2),sin(p2))*r[i]);
                }
                p1=p2;
                arg[j].second?cnt--:cnt++;
            }
        }
        else sum+=2*pi*r[i]*r[i];
    }
    return (sum+fabs(sum1))*0.5;
}


//多圆面积并Ver 2.0
//ans1 , ans2 初始化
double ans[1005],ans2[1005];
const double eps=1e-7;
const double pi=acos(-1.0);
pair<double,bool>arg[2005];
void cir_union(Point c[],double r[],int n)
{
    double d,p1,p2,p3;
    for(int i=0;i<n;i++)
    {
        int k=0,cnt=1;
        for(int j=0;j<n;j++)
            if(i!=j&&sgn((d=c[i]/c[j])-r[i]-r[j])<=0)
            {
                if(sgn(d+r[i]-r[j])<=0)cnt++;
                else if(sgn(d+r[j]-r[i])<=0);
                else
                {
                    p3=acos((r[i]*r[i]+d*d-r[j]*r[j])/(2.0*r[i]*d));
                    p2=atan2(c[j].y-c[i].y,c[j].x-c[i].x);
                    p1=p2-p3;p2=p2+p3;
                    if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                    if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                    arg[k++]=make_pair(p1,0);arg[k++]=make_pair(p2,1);
                }
            }
        if(k)
        {
            sort(arg,arg+k);
            p1=arg[k-1].first-2*pi;
            p3=r[i]*r[i];
            for(int j=0;j<k;j++)
            {
                p2=arg[j].first;
                ans[cnt]+=(c[i]+Point(cos(p1),sin(p1))*r[i])*(c[i]+Point(cos(p2),sin(p2))*r[i]);
                ans2[cnt]+=(p2-p1-sin(p2-p1))*p3;
                p1=p2;
                arg[j].second?cnt--:cnt++;
            }
        }
        else ans2[cnt]+=2*pi*r[i]*r[i];
    }
    for(int i=1;i<=n;i++)
        ans[i]=(fabs(ans[i])+ans2[i])*0.5;
    //ans[i]为覆盖i次及以上的面积
}
