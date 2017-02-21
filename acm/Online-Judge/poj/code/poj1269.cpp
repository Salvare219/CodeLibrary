#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

using namespace std;





struct Point

{

    double x,y;

    Point(double a=0,double b=0){x=a;y=b;}

    Point operator-(Point a){return Point(x-a.x,y-a.y);}

    Point operator+(Point a){return Point(x+a.x,y+a.y);}

    Point operator/(double a){return Point(x/a,y/a);}

    Point operator*(double a){return Point(x*a,y*a);}

    bool operator==(Point a){return x==a.x&&y==a.y;}

}po[5];

struct Line

{

   int a,b,c;

    Line(Point p0=Point(1,1),Point p1=Point())

    {

        a=p1.y-p0.y;b=p0.x-p1.x;

        c=(p0.y-p1.y)*p0.x+(p1.x-p0.x)*p0.y;

        int d=max(abs(a),abs(b));

        d=a?__gcd(d,a):d;d=b?__gcd(d,b):d;

        d=abs(c?__gcd(d,c):d);

        if(a<0 || (a==0 && b<0)) d=-d;

        a/=d;b/=d;c/=d;

    }

}l1,l2;

Point intersect(Line a,Line b)

{

    return Point(1.0*(a.b*b.c-b.b*a.c)/(b.b*a.a-a.b*b.a),

                 1.0*(b.a*a.c-a.a*b.c)/(a.a*b.b-b.a*a.b));

}

int main()

{

    int t;

    scanf("%d",&t);

    puts("INTERSECTING LINES OUTPUT");

    while(t--)

    {

        for(int i=0;i<4;i++)

            scanf("%lf%lf",&po[i].x,&po[i].y);

        l1=Line(po[0],po[1]);l2=Line(po[2],po[3]);

        if(l1.a==l2.a && l1.b==l2.b)

        {

            if(l1.c==l2.c) puts("LINE");

            else puts("NONE");

        }

        else

        {

            po[0]=intersect(l1,l2);

            printf("POINT %.2f %.2f\n",po[0].x,po[0].y);

        }

    }

    puts("END OF OUTPUT");

    return 0;

}

