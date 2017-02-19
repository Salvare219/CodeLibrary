#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


double wall[60][5];
double pos[60];
double dp[60][5];
int n;
struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(double a){return Point(x/a,y/a);}
    Point operator*(double a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
};
double dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cross(Point a,Point b,Point c,Point d)
{
    if(min(a.x,b.x) <= max(c.x,d.x) && min(c.x,d.x) <= max(a.x,b.x) &&
       min(a.y,b.y) <= max(c.y,d.y) && min(c.y,d.y) <= max(a.y,b.y))
       return xmult(a,b,c)*xmult(a,b,d)<0.0 && xmult(c,d,a)*xmult(c,d,b)<0.0;
    else return 0;
}
bool ok(int s,int t,int a,int b)
{
    for(int i=s+1;i<t;i++)
    {
        if(cross(Point(pos[s],wall[s][a]),Point(pos[t],wall[t][b]),Point(pos[i],wall[i][1]),Point(pos[i],wall[i][2]))) return 0;
        if(cross(Point(pos[s],wall[s][a]),Point(pos[t],wall[t][b]),Point(pos[i],0.0),Point(pos[i],wall[i][0]))) return 0;
        if(cross(Point(pos[s],wall[s][a]),Point(pos[t],wall[t][b]),Point(pos[i],wall[i][3]),Point(pos[i],10.0))) return 0;
    }
    return 1;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==-1) break;
        int x,y;
        for(int i=1;i<=n+1;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=1e10;
        pos[0]=0.0;wall[0][0]=wall[0][1]=wall[0][2]=wall[0][3]=5.0;
        pos[n+1]=10.0;wall[n+1][0]=wall[n+1][1]=wall[n+1][2]=wall[n+1][3]=5.0;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf%lf",pos+i,&wall[i][0],&wall[i][1],&wall[i][2],&wall[i][3]);
        dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0.0;n++;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=0;k<16;k++)
                {
                    x=k&3;y=k>>2;
                    if(ok(i,j,x,y))
                        dp[j][y]=min(dp[j][y],dp[i][x]+dis(Point(pos[i],wall[i][x]),Point(pos[j],wall[j][y])));
                }
        printf("%.2f\n",dp[n][0]);
    }
    return 0;
}
