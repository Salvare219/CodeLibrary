#include<bits/stdc++.h>
using namespace std;


struct Point
{
    long long x,y;
    int i;
    Point(long long a=0,long long b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    bool operator<(const Point&a)const
    {
        long long temp=*this*a;
        return temp>0||(temp==0&&x*x+y*y<a.x*a.x+a.y*a.y);
    }
}po[5050],hul[5050];
void convex(Point h[],int n,Point ans[],int &k)
{
    for(int i=1;i<n;i++)
        if(h[0].y>h[i].y||(h[0].y==h[i].y&&h[0].x>h[i].x))swap(h[0],h[i]);
    Point sta=h[0];
    for(int i=0;i<n;i++)
        h[i].x-=sta.x,h[i].y-=sta.y;
    sort(h+1,h+n);k=min(2,n);
    for(int i=0;i<n;i++)
        h[i].x+=sta.x,h[i].y+=sta.y;
    ans[0]=h[0];ans[1]=h[1];
    for(int i=2;i<n;i++)
    {
        while(k>1&&(ans[k-1]-ans[k-2])*(h[i]-ans[k-2])<=0)k--;
        ans[k++]=h[i];
    }
}
void cal(int n,long long &s,int &a,int &b,int &c)
{
    int p1=1,p2=2;
    po[n]=po[0];
    long long ans=0.0;
    for(int i=0;i<n;i++)
    {
        if(p1==i)p1==n-1?p1=0:p1++;
        if(p2==p1)p2==n-1?p2=0:p2++;
        while((po[p1]-po[i])*(po[p2+1]-po[i])-(po[p1]-po[i])*(po[p2]-po[i])>0)
            p2==n-1?p2=0:p2++;
        while((po[p1+1]-po[i])*(po[p2]-po[i])-(po[p1]-po[i])*(po[p2]-po[i])>0)
            p1==n-1?p1=0:p1++;
        long long sum=(po[p1]-po[i])*(po[p2]-po[i]);
        if(sum-ans>0)
        {
            ans=sum;
            a=po[i].i;b=po[p1].i;c=po[p2].i;
        }
    }
    s=ans;
}
long long tri(int x,int y,int z)
{
    x--;y--;z--;
    long long c=(po[y]-po[x])*(po[z]-po[x]);
    return abs(c);
}
int main()
{
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    int n,k;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&po[i].x,&po[i].y),po[i].i=i+1;
    convex(po,n,hul,k);
    int p1=1,p2=2;
    hul[k]=hul[0];
    long long ans=-1;
    int c[9];
    for(int i=0;i<k;i++)
    {
        int cnt=0;
        long long sum=abs((hul[i+1]-hul[i])*(hul[(i-1+k)%k]-hul[i]));
        for(int j=0;j<k;j++)
            if(j!=i)po[cnt++]=hul[j];
        long long area;
        int x,y,z;
        cal(cnt,area,x,y,z);
        if(area-sum-ans>0)
        {
            ans=area-sum;
            c[0]=x;c[1]=y;c[2]=z;
            c[3]=hul[i].i;c[4]=hul[i+1].i;c[5]=hul[(i-1+k)%k].i;
        }
    }
    if(ans&1)printf("%I64d.5\n",ans/2);
    else printf("%I64d.0\n",ans/2);
    for(int i=0;i<6;i+=3)
        printf("%d %d %d\n",c[i],c[i+1],c[i+2]);
    return 0;
}