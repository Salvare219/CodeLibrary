#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct Point
{
    long long x,y;
    double ph;
    Point(long long a=0.0,long long b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    long long operator/(const Point&a)const{return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}
    double arg(){return atan2(y,x);}

}po[100500],c,tp[100500];
double pp[100500];
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
int main()
{
    freopen("stars.in","r",stdin);
    freopen("stars.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    int k=0;
    for(int i=0;i<=n;i++)
    {
        if(i<n)
        {
            scanf("%I64d%I64d",&c.x,&c.y);
            while(k>1&&(po[k-2]-po[k-1])*(c-po[k-2])==0)
            {
                k--;
            }
            po[k++]=c;
        }
        else
        {
            c=po[0];
            while(k>1&&(po[k-2]-po[k-1])*(c-po[k-2])==0)
            {
                k--;
            }
        }
    }
    double o=1e5,op=1e-5;
    int f=0;
    for(int i=0;i<k;i++)
    {
        po[i].ph=po[i].arg();
        if(po[i].ph<o)
        {
            o=po[i].ph;
            f=i;
        }
        op=max(op,po[i].ph);
    }
    int d=1;
    if(sgn(po[(f+1)%k].ph-op)==0)d=-1;
    for(int i=0;i<k;i++)
    {
        tp[i]=po[(f+d*i+k)%k];
        pp[i]=tp[i].ph;
    }
    for(int i=0;i<k;i++)
        po[i]=tp[i];

    Point z=Point(0,0);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        scanf("%I64d%I64d",&c.x,&c.y);
        c.ph=c.arg();
        int ind=lower_bound(pp,pp+k,c.ph)-pp;
        int l=(ind-2+k)%k,r=(ind+2+k)%k;

        int st=-1,cnt=0;

        int cc=l;
        do
        {
            if(sgn(pp[cc]-c.ph)==0)
            {
                if(cnt==0)
                    st=cc;
                cnt++;
            }
            cc=(cc+1)%k;
        }while(cc!=(r+1)%k);


        if(st==-1)
            st=(ind-1+k)%k;

        if(cnt>=2)
        {
            long long d=max(po[st]/z,po[(st+1)%k]/z);
            long long d2=c/z;
            if(d>=d2)
                ans++;
        }
        else
        {
            l=st;r=(st+1)%k;
            long long d=abs(po[r]*po[l]);
            long long d2=abs((po[l]-c)*(po[r]-c))+abs((po[r]-c)*(z-c))+abs((z-c)*(po[l]-c));
            if(d==d2)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
