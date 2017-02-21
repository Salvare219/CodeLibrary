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

    Point(long long a=0,long long b=0){x=a;y=b;}

    Point operator-(Point a){return Point(x-a.x,y-a.y);}

    Point operator+(Point a){return Point(x+a.x,y+a.y);}

    Point operator/(long long a){return Point(x/a,y/a);}

    Point operator*(long long a){return Point(x*a,y*a);}

    bool operator==(Point a){return x==a.x&&y==a.y;}

}po[1005];

int n;

long long temp;

int stack[1005],k;

long long xmult(Point p0,Point p1,Point p2)

{

    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);

}

long long dot(Point p0,Point p1,Point p2)

{

    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);

}

long long sdis(Point p1,Point p2)

{

    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);

}

bool cmp(Point p1,Point p2)

{

    temp=xmult(po[0],p1,p2);

    if(temp>0 || (temp==0 && sdis(po[0],p1)<sdis(po[0],p2))) return 1;

    else return 0;

}

void convex(int n)

{

    for(int i=1;i<n;i++)

        if(po[0].y>po[i].y || (po[0].y==po[i].y && po[0].x>po[i].x))

            swap(po[0],po[i]);

    sort(po+1,po+n,cmp);

    stack[0]=0;stack[1]=1;

    k=min(2,n);

    for(int i=2;i<n;i++)

    {

        while(k-1 && xmult(po[stack[k-2]],po[stack[k-1]],po[i])<=0) k--;

        stack[k++]=i;

    }

}

bool pos_line(Point p0,Point p1,Point p2)

{

    return xmult(p0,p1,p2)==0 && dot(p0,p1,p2)<=0;

}

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        int n;

        scanf("%d",&n);

        for(int i=0;i<n;i++)

            scanf("%lld%lld",&po[i].x,&po[i].y);

        convex(n);

        stack[k]=stack[0];

        bool f=1;

        if(n<=5) f=0;

        for(int i=0;i<k && f;i++)

        {

            bool fs=0;

            for(int j=0;j<n && !fs;j++)

                if(j!=stack[i] && j!=stack[i+1])

                    fs=pos_line(po[j],po[stack[i]],po[stack[i+1]]);

            if(!fs) f=0;

        }

        puts(f?"YES":"NO");

    }

    return 0;

}

