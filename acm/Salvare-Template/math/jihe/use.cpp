//asin(y/x) 范围 [-pi/2,pi/2]
//acos(y/x) 范围 [0,pi]
//atan(y/x) 范围 [-pi/2,pi/2]
//atan2(y,x) 范围 [-pi,pi] x 轴正向为 0

struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
    double arg(){return atan2(y,x);}        //[-pi,pi] x 轴正向逆时针为正
};    //点类

struct Line
{
    int a,b,c;   //a*x+b*y+c=0 (满足 a>0 或 a=0,b>0  且为最简)
    Line(Point p0=Point(1,1),Point p1=Point())  //必须保证两点不重合
    {
        a=p1.y-p0.y;b=p0.x-p1.x;
        c=(p0.y-p1.y)*p0.x+(p1.x-p0.x)*p0.y;  //double 的话到这
        int d=max(abs(a),abs(b));
        d=a?__gcd(d,a):d;d=b?__gcd(d,b):d;
        d=abs(c?__gcd(d,c):d);
        if(a<0 || (a==0 && b<0)) d=-d;
        a/=d;b/=d;c/=d;
    }
    Point intersect(Line l)    //求直线交点 要保证不平行或重合
    {
        return Point(1.0*(b*l.c-l.b*c)/(l.b*a-b*l.a),
                     1.0*(l.a*c-a*l.c)/(a*l.b-l.a*b));
    }
};   //直线类(解析式)

struct Line
{
    Point s,t;
    double arg;
    Line(){}
    Line(Point a,Point b){s=a;t=b;arg=atan2(b.y-a.y,b.x-a.x);}
    Point operator&(const Line&a)    //求直线交点 要保证不平行或重合
    {return (t-s)*((s-a.s)*(a.s-a.t))/((s-t)*(a.s-a.t))+s;}
    bool operator<(const Line&a)
    {
        if(fabs(arg-a.arg)>eps)return arg<a.arg;
        else return (a.s-s)*(t-s)>0;
    }
};   //直线类(两点式)

const double eps = 1e-8;
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}

inline Point line_cro(Point p1,Point p2,Point p3,Point p4)  //直线求交点
{
    return (p2-p1)*((p1-p3)*(p3-p4))/((p1-p2)*(p3-p4))+p1;
}

inline bool pos_line(Point p0,Point p1,Point p2)  //p0 是否在 p1p2 上
{
    return sgn((p1-p0)*(p2-p0))==0 && sgn((p1-p0)%(p2-p0))<=0;
}

inline bool cross(Point p0,Point p1,Point p2,Point p3) //判断线段 p0p1,p2p3 是否相交 端点相交也算
{
    if(min(p0.x,p1.x) <= max(p2.x,p3.x) && min(p2.x,p3.x) <= max(p0.x,p1.x) &&
       min(p0.y,p1.y) <= max(p2.y,p3.y) && min(p2.y,p3.y) <= max(p0.y,p1.y))
       return sgn(((p1-p0)*(p2-p0))*((p1-p0)*(p3-p0)))<=0 && sgn(((p3-p2)*(p0-p2))*((p3-p2)*(p1-p2)))<=0;
    else return 0;
}

inline bool cross(Point p0,Point p1,Point p2,Point p3) //判断线段 p0p1,p2p3 是否相交 端点相交不算
{
    return sgn(((p1-p0)*(p2-p0))*((p1-p0)*(p3-p0)))<0 && sgn(((p3-p2)*(p0-p2))*((p3-p2)*(p1-p2)))<0;
}

inline Point rota(Point p0,Point p1,double deg)  //p1 绕 p0 顺时针 deg 弧度
{
    Point n=p1-p0;
    return p0+Point(n.x*cos(deg)+n.y*sin(deg),n.y*cos(deg)-n.x*sin(deg));
}

bool inpol(Point pol[],int n,Point p1)
{
    int cnt=0,i;
    Point p2;pol[n]=pol[0];
    for(i=n;i>0;i--)
        if(sgn((pol[i-1]-p1)*(pol[i]-p1))==0&&sgn((pol[i-1]-p1)%(pol[i]-p1))!=1)
            return 1;
    while(i<n)
    {
        p2=Point(rand()+maxn,rand()+maxn);
        for(i=0;i<n;i++)
        {
            if(!sgn((p2-p1)*(pol[i]-p1))){cnt=0;break;}
            if(sgn((p2-pol[i])*(pol[i+1]-pol[i]))*sgn((p1-pol[i])*(pol[i+1]-pol[i]))==-1
               &&sgn((p2-p1)*(pol[i+1]-p1))*sgn((p2-p1)*(pol[i]-p1))==-1)cnt++;
        }
    }
    return cnt&1;
}

double R;  //球半径
double sph_dis(double lat1,double lng1,double lat2,double lng2) //纬度 经度
{
    double radLat1=lat1*pi/180.0;
    double radLat2=lat2*pi/180.0;
    double a=radLat1-radLat2;
    double b=lng1*pi/180.0-lng2*pi/180.0;
    double s=2*asin(sqrt(sin(a/2)*sin(a/2)+cos(radLat1)*cos(radLat2)*sin(b/2)*sin(b/2)));
    return s*R;
}
