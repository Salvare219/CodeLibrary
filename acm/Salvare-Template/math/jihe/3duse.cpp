struct Point_3
{
    double x,y,z;
    Point_3(double a=0,double b=0,double c=0){x=a;y=b;z=c;}
    Point_3 operator+(const Point_3&a)const{return Point_3(x+a.x,y+a.y,z+a.z);}
    Point_3 operator-(const Point_3&a)const{return Point_3(x-a.x,y-a.y,z-a.z);}
    Point_3 operator*(const double&a)const{return Point_3(x*a,y*a,z*a);}
    Point_3 operator/(const double&a)const{return Point_3(x/a,y/a,z/a);}
    Point_3 operator*(const Point_3&a)const{return Point_3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);}
    double operator/(const Point_3&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y)+(a.z-z)*(a.z-z));}
    double operator%(const Point_3&a)const{return x*a.x+y*a.y+z*a.z;}
};

Point_3 rota_3(Point_3 p,Point_3 v, double arg)     //右手螺旋 arg 弧度 v 必须是单位向量
{
    double rot[3][3],cs=cos(arg),si=sin(arg);
    rot[0][0]=cs+(1-cs)*v.x*v.x;
    rot[0][1]=(1-cs)*v.x*v.y-si*v.z;
    rot[0][2]=(1-cs)*v.x*v.z+si*v.y;
    rot[1][0]=(1-cs)*v.y*v.x+si*v.z;
    rot[1][1]=cs+(1-cs)*v.y*v.y;
    rot[1][2]=(1-cs)*v.y*v.z-si*v.x;
    rot[2][0]=(1-cs)*v.z*v.x-si*v.y;
    rot[2][1]=(1-cs)*v.z*v.y+si*v.x;
    rot[2][2]=cs+(1-cs)*v.z*v.z;
    return Point_3(p.x*rot[0][0]+p.y*rot[0][1]+p.z*rot[0][2],
                   p.x*rot[1][0]+p.y*rot[1][1]+p.z*rot[1][2],
                   p.x*rot[2][0]+p.y*rot[2][1]+p.z*rot[2][2]);
}

Point_3 projection(Point_3 z,Point_3 vec,Point_3 p,Point_3 dir)  // vec 单位面法向量 dir 单位投影向量 *****
{
    int f=sgn(z*dir);
    if(f==0)return Point_3(1e20,1e20,1e20);
    else
    {
        double s=(z-p)%vec;
        return p+s*dir*f;
    }
}
