#include<cstdio>


#include<cstring>


#include<cmath>


#include<algorithm>


#include<vector>


#include<queue>


using namespace std;








struct Point


{


    int x,y;


    Point(int a=0.0,int b=0.0){x=a;y=b;}


    Point operator-(Point a){return Point(x-a.x,y-a.y);}


    Point operator+(Point a){return Point(x+a.x,y+a.y);}


    Point operator/(int a){return Point(x/a,y/a);}


    Point operator*(int a){return Point(x*a,y*a);}


    bool operator==(Point a){return x==a.x&&y==a.y;}


}p,p1,s;


int xmult(Point p0,Point p1,Point p2)


{


    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);


}


int main()


{


    int t,ti=1;


    scanf("%d",&t);


    while(t--)


    {


        int n;


        scanf("%d",&n);


        int area=0,edge=0;p=Point(0,0);


        for(int i=0;i<n;i++)


        {


            scanf("%d%d",&p1.x,&p1.y);


            if(p1.x==0) edge+=abs(p1.y);


            else if(p1.y==0) edge+=abs(p1.x);


            else edge+=abs(__gcd(p1.x,p1.y));


            p1=p+p1;


            area+=xmult(Point(0,0),p,p1);p=p1;


        }


        area=abs(area);


        printf("Scenario #%d:\n%d %d %.1f\n\n",ti++,(area+2-edge)/2,edge,area/2.0);


    }


    return 0;


}


