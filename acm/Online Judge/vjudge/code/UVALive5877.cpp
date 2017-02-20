#include<bits/stdc++.h>
using namespace std;


struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b){x=a;y=b;}
    double operator/(const Point&a)const{return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);}
}p[2000];
int n;
int d[2000];
int inq[2000];
double len;
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
int bfs(int s,int t)
{
    for(int i=1;i<=n;i++)
        inq[i]=0;
    d[s]=0;inq[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=1;i<=n;i++)
            if(inq[i]==0)
            {
                double dis=p[i]/p[x];
                if(sgn(len-dis)>=0)
                {
                    d[i]=d[x]+1;
                    if(i==t)return d[i];
                    inq[i]=1;
                    q.push(i);
                }
            }
    }
    return -1;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int s,f;
        double l1,l2;
        scanf("%d%d%d%lf%lf",&n,&s,&f,&l1,&l2);
        len=(l1+l2)*(l1+l2);
        for(int i=1;i<=n;i++)
        {
            double x,y;
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        f=bfs(s,f);
        if(f==-1)puts("Impossible");
        else printf("%d\n",f);
    }
    return 0;
}
