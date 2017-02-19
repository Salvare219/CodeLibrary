#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

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

}po[100005];

long long temp;

int stack[100005],k;

long long abss(long long a)

{

    return a>0?a:-a;

}

long long xmult(Point p0,Point p1,Point p2)

{

    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);

}

long long sdis(Point p1,Point p2)

{

    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);

}

bool cmp(Point p1,Point p2)

{

    temp=xmult(po[0],p1,p2);

    return temp>0 || (temp==0 && sdis(po[0],p1)<sdis(po[0],p2));

}

void convex(int n)

{

    for(int i=1;i<n;i++)

        if(po[0].y>po[i].y || (po[0].y==po[i].y && po[0].x>po[i].x))

            swap(po[0],po[i]);

    sort(po+1,po+n,cmp);

    stack[0]=0;stack[1]=1;

    k=min(2,n);

    for(int i=0;i<n;i++)

    {

        while(k-1 && xmult(po[stack[k-2]],po[stack[k-1]],po[i])<=0)

            k--;

        stack[k++]=i;

    }

}

int main()

{

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)

        scanf("%lld%lld",&po[i].x,&po[i].y);

    convex(n);

    int f=0;stack[k]=stack[0];

    long long ans=0,dis;

    for(int i=0;i<k;i++)

    {

        while(abss(xmult(po[stack[i]],po[stack[i+1]],po[stack[f]]))<abss(xmult(po[stack[i]],po[stack[i+1]],po[stack[f+1]])))

            f=f==k-1?0:f+1;

        dis=max(sdis(po[stack[i]],po[stack[f]]),sdis(po[stack[i+1]],po[stack[f]]));

        ans=max(ans,dis);

    }

    printf("%d\n",ans);

    return 0;

}

