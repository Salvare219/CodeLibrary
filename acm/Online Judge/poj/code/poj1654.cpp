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

    Point(long long a=0.0,long long b=0.0){x=a;y=b;}

    Point operator-(Point a){return Point(x-a.x,y-a.y);}

    Point operator+(Point a){return Point(x+a.x,y+a.y);}

    Point operator/(long long a){return Point(x/a,y/a);}

    Point operator*(long long a){return Point(x*a,y*a);}

    bool operator==(Point a){return x==a.x&&y==a.y;}

}p,p1,d[10];

char s[1000005];

long long xmult(Point p0,Point p1,Point p2)

{

    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);

}

int main()

{

    int t;

    scanf("%d",&t);

    d[8]=Point(0,1);d[2]=Point(0,-1);

    d[6]=Point(1,0);d[4]=Point(-1,0);

    d[9]=Point(1,1);d[7]=Point(-1,1);

    d[3]=Point(1,-1);d[1]=Point(-1,-1);

    while(t--)

    {

        scanf("%s",s);p=Point(0,0);

        long long area=0;

        for(int i=0;s[i]!='5';i++)

        {

            p1=p+d[s[i]-'0'];

            area+=xmult(Point(0,0),p,p1);

            p=p1;

        }

        area=area>0?area:-area;

        if(area&1) printf("%lld.5\n",area/2);

        else printf("%lld\n",area/2);

    }

    return 0;

}

