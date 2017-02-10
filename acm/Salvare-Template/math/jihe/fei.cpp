
//(1)若三角形ABC的 3 个内角均小于 120 °，那么 3 条距离连线正好三
//   等分费马点所在的周角。所以三角形的费马点也称为三角形的等角中心。

//(2)若三角形有一内角不小于 120 度，则此钝角的顶点就是距离和最小的点。


const double eps=1e-8;
const double pi=acos(-1.0);
struct point_t
{
    double x, y;
    point_t() { }
    point_t(double tx, double ty) : x(tx), y(ty) { }
    point_t operator-(const point_t &r) const
    {
        return point_t(x - r.x, y - r.y);
    }
    point_t operator+(const point_t &r) const
    {
        return point_t(x + r.x, y + r.y);
    }
    point_t operator*(const double r) const
    {
        return point_t(x * r, y * r);
    }
    point_t operator/(const double r) const
    {
        return point_t(x / r, y / r);
    }
} p[4];

int dblcmp(double x)
{
    return (x < -eps ? -1 : x > eps);
}

double dist(point_t p1, point_t p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double cross(point_t p1, point_t p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

double dot(point_t p1, point_t p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}

double angle(point_t p1, point_t p2, point_t p3)
{
    double d = dot(p2 - p1, p3 - p1) / dist(p1, p2) / dist(p1, p3);
    return d;
}

point_t inter(point_t a, point_t b, point_t c, point_t d)
{
    point_t p1 = b - a, p2 = d - c;
    double a1 = p1.y, b1 = -p1.x, c1;
    double a2 = p2.y, b2 = -p2.x, c2;
    c1 = a1 * a.x + b1 * a.y;
    c2 = a2 * c.x + b2 * c.y;
    return point_t((c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1), (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1));
}

point_t ver(point_t p1, point_t p2)
{
    point_t v = (p2 - p1) / 2 * sqrt(3.0);
    swap(v.x, v.y);
    v.x = -v.x;
    return v;
}

point_t fermat(point_t p1, point_t p2, point_t p3)
{
    if (2*angle(p1, p2, p3) < -1) return p1;
    if (2*angle(p2, p1, p3) < -1) return p2;
    if (2*angle(p3, p1, p2) < -1) return p3;
    point_t v1 = ver(p1, p2);
    point_t m1 = (p1 + p2) / 2;
    if (dblcmp(cross(p3 - p1, p2 - p1)) * dblcmp(cross(v1 + m1 - p1, p2 - p1)) > 0) v1.x = -v1.x, v1.y = -v1.y;
    m1 = m1 + v1;
    point_t v2 = ver(p1, p3);
    point_t m2 = (p1 + p3) / 2;
    if (dblcmp(cross(p2 - p1, p3 - p1)) * dblcmp(cross(v2 + m2 - p1, p3 - p1)) > 0) v2.x = -v2.x, v2.y = -v2.y;
    m2 = m2 + v2;
    return inter(p3, m1, p2, m2);
}

int main()
{
    freopen("1.txt","r",stdin);
    int a,b,c,d,e,f;
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=-1)
    {
        if(a==c && b==d && a==e && b==f) printf("%.6lf %.6lf\n",1.0*a,1.0*b);
        else if(a==c && b==d) printf("%.6lf %.6lf\n",1.0*a,1.0*b);
        else if(a==e && b==f) printf("%.6lf %.6lf\n",1.0*a,1.0*b);
        else if(c==e && d==f) printf("%.6lf %.6lf\n",1.0*c,1.0*d);
        else
        {
            p[0].x=1.0*a;p[0].y=1.0*b;p[1].x=1.0*c;p[1].y=1.0*d;p[2].x=1.0*e;p[2].y=1.0*f;
            point_t f=fermat(p[0],p[1],p[2]);
            printf("%.6lf %.6lf\n",f.x,f.y);
        }
    }
    return 0;
}



//另:变步长法（近似算法）

struct point
{
    double x,y;
}p[3];
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point fermentpoint(point a,point b,point c)
{
    point u,v;
    double step=fabs(a.x)+fabs(a.y)+fabs(b.x)+fabs(b.y)+fabs(c.x)+fabs(c.y);
    int i,j,k;
    u.x=(a.x+b.x+c.x)/3;
    u.y=(a.y+b.y+c.y)/3;
    while(step>1e-10)
        for(k=0;k<10;step/=2,k++)
            for(i=-1;i<=1;i++)
                for(j=-1;j<=1;j++)
                {
                    v.x=u.x+step*i;
                    v.y=u.y+step*j;
                    if(dis(u,a)+dis(u,b)+dis(u,c)>dis(v,a)+dis(v,b)+dis(v,c))
                        u.x=v.x,u.y=v.y;
                }
    return u;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    while(scanf("%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y)==6)
    {
        point a=fermentpoint(p[0],p[1],p[2]);
        printf("%.6lf %.6lf\n",a.x,a.y);
    }
}
