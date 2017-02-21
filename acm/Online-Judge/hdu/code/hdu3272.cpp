#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    double x,y;
    double operator/(const Point&a)const
    {return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}a,b,h;
const double eps=1e-8;
int sgn(double x)
{return fabs(x)<eps?0:(x>0?1:-1);}
inline int Int()
{
    int a=0;char c=getc(stdin),s;
    while(c<'0')s=c,c=getc(stdin);
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getc(stdin);
    return s!='-'?a:-a;
}
int main()
{
    int t=Int();
    while(t--)
    {
        a.x=Int();a.y=Int();b.x=Int();b.y=Int();h.x=Int();h.y=Int();
        if(sgn(h.x)<0)h.x=-h.x,a.x=-a.x,b.x=-b.x;
        if(sgn(h.y)<0)h.y=-h.y,a.y=-a.y,b.y=-b.y;
        int p[7]={1,2,3,4,0};
        double ans=1e10;
        do
        {
            Point now=h,te;
            double dis=0.0;
            bool x=0,y=0;
            for(int i=0;i<5;i++)
                if(p[i]==1)x=1;
                else if(p[i]==2)y=1;
                else
                {
                    if(p[i]==3)te=a;
                    else if(p[i]==4)te=b;
                    else te=h;
                    if(x)now.x=sgn(te.x*now.x)>0?-now.x:now.x;
                    if(y)now.y=sgn(te.y*now.y)>0?-now.y:now.y;
                    dis+=now/te;now=te;
                    x=0;y=0;
                }
            ans=min(ans,dis);
        }while(next_permutation(p,p+4));
        printf("%.2f\n",ans);
    }
    return 0;
}
