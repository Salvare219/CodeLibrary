//1. 求凸包
//longlong 版本
struct Point
{
    long long x,y;
    Point(long long a=0,long long b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        long long temp=*this*a;
        return temp>0||(temp==0&&x*x+y*y<a.x*a.x+a.y*a.y);
    }
};
int convex(Point h[],int n,Point ans[],int &k)
{
    for(int i=1;i<n;i++)
        if(h[0].y>h[i].y||(h[0].y==h[i].y&&h[0].x>h[i].x))swap(h[0],h[i]);
    Point sta=h[0];
    for(int i=0;i<n;i++)h[i]=h[i]-sta;
    sort(h+1,h+n);k=min(2,n);
    for(int i=0;i<n;i++)h[i]=h[i]+sta;
    ans[0]=h[0];ans[1]=h[1];
    for(int i=2;i<n;i++)
    {
        while(k>1&&(ans[k-1]-ans[k-2])*(h[i]-ans[k-2])<=0)k--;
        ans[k++]=h[i];
    }
}

//double 版本
struct Point
{
    double x,y;
    Point(double a=0,double b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        double temp=*this*a;
        return sgn(temp)==1||(sgn(temp)==0&&sgn(a.x*a.x+a.y*a.y-x*x-y*y)==1);
    }
};
int convex(Point h[],int n,Point ans[],int &k)
{
    for(int i=1;i<n;i++)
        if(sgn(h[0].y-h[i].y)==1||(sgn(h[0].y-h[i].y)==0&&sgn(h[0].x-h[i].x)==1))swap(h[0],h[i]);
    Point sta=h[0];
    for(int i=0;i<n;i++)h[i]=h[i]-sta;
    sort(h+1,h+n);k=min(2,n);
    for(int i=0;i<n;i++)h[i]=h[i]+sta;
    ans[0]=h[0];ans[1]=h[1];
    for(int i=2;i<n;i++)
    {
        while(k>1&&sgn((ans[k-1]-ans[k-2])*(h[i]-ans[k-2]))!=1)k--;
        ans[k++]=h[i];
    }
}

//2. 最远点对（旋转卡壳）
long long ans=0;
int p=1;
hul[k]=hul[0];
for(int i=0;i<k;i++)
{
    while(fabs((hul[i+1]-hul[i])*(hul[p+1]-hul[i]))>fabs((hul[p]-hul[i])*(hul[i+1]-hul[i])))
        p==k-1?p=0:p++;
    ans=max(ans,max(hul[i+1]/hul[p],hul[i]/hul[p]));
}

//3. 最小矩形（三个旋转卡壳）
int p=1,p1=1,p2=1;
double ans=1e10,a,b;
hul[k]=hul[0];
for(int i=0;i<k;i++)
{
    while(abs((hul[i+1]-hul[i])*(hul[p+1]-hul[i]))>abs((hul[i+1]-hul[i])*(hul[p]-hul[i])))
        p==k-1?p=0:p++;
    while((hul[p1+1]-hul[p1])%(hul[i+1]-hul[i])>0)
        p1==k-1?p1=0:p1++;
    while((hul[i+1]-hul[i])*(hul[p2+1]-hul[p2])>0||(hul[p2+1]-hul[p2])%(hul[i+1]-hul[i])<0)
        p2==k-1?p2=0:p2++;
    a=2*abs((hul[i+1]-hul[i])*(hul[p]-hul[i]))/(hul[i]/hul[i+1]);
    b=2*abs((hul[p1]-hul[p2])%(hul[i+1]-hul[i]))/(hul[i]/hul[i+1]);
    ans=min(a+b,ans);
}

//4. 两个凸包最近点对
inline double p2l_dist(Point p1,Point p2,Point p3)
{
    Point d=Point(-(p3-p2).y,(p3-p2).x);
    if(sgn(d*(p2-p1))==sgn(d*(p3-p1)))return min(p1/p2,p1/p3);
    else
    {
        d=d/(d/Point(0,0));
        return fabs((p3-p1)%d);
    }
}
inline double seg_dist(Point p1,Point p2,Point p3,Point p4)
{
    double t1=min(p2l_dist(p1,p3,p4),p2l_dist(p2,p3,p4));
    double t2=min(p2l_dist(p3,p1,p2),p2l_dist(p4,p1,p2));
    return min(t1,t2);
}
double convex_dist(Point h1[],int n,Point h2[],int m)
{
    int p1=0,p2=0,cnt=n+1;
    for(int i=1;i<n;i++)
        if(sgn(h1[p1].y-h1[i].y)>0)p1=i;
    for(int i=1;i<m;i++)
        if(sgn(h2[p2].y-h2[i].y)<0)p2=i;
    h1[n]=h1[0];h2[m]=h2[0];
    double ans=1e10;
    while(cnt--)
    {
        ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2],h2[p2+1]));
        while(sgn((h2[p2+1]-h2[p2])*(h1[p1+1]-h1[p1]))<0)
        {
            p2==m-1?p2=0:p2++;
            ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2],h2[p2+1]));
        }
        p1==n-1?p1=0:p1++;
    }
    return ans;
}
