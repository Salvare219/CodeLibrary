#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct Point
{
    int x,y,v,l;
    Point(int a=0,int b=0){x=a;y=b;}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(int a){return Point(x/a,y/a);}
    Point operator*(int a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
}po[105],sb[105];
int temp;
int stack[105],k;
int xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int sdis(Point p1,Point p2)
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
int main()
{
    int n,ti=1;
    bool ex=0;
    while(scanf("%d",&n) && n)
    {
        if(ex) putchar(10);
        ex=1;
        printf("Forest %d\nCut these trees:",ti++);
        for(int i=0;i<n;i++)
            scanf("%lld%lld%d%d",&sb[i].x,&sb[i].y,&sb[i].v,&sb[i].l);
        int lim=1<<n,cost=0x3fffffff,ans;
        double f;
        for(int i=1;i<lim;i++)
        {
            int v=0,l=0,r=0;
            for(int j=0;j<n;j++)
                if((1<<j)&i) po[r++]=sb[j];
                else l+=sb[j].l,v+=sb[j].v;
            convex(r);double len=0.0;
            stack[k]=stack[0];
            for(int i=0;i<k;i++)
                len+=sqrt(sdis(po[stack[i]],po[stack[i+1]]));
            if(len<=l && cost>v) cost=v,ans=i,f=l-len;
        }
        for(int i=0;i<n;i++)
            if(((1<<i)&ans)==0) printf(" %d",i+1);
        printf("\nExtra wood: %.2f\n",f);
    }
    return 0;
}
