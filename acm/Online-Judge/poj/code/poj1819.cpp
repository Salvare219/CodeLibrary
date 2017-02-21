#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Cir
{
    double x,r;
}po[2005];
bool v[2005];
const double eps = 1e-8;
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
int main()
{
    int n;scanf("%d",&n);
    double r,tx,ps,right;
    int c,f;
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&r);
        ps=r;c=-1;
        for(int j=0;j<i;j++)
        {
            tx=2.0*sqrt(po[j].r*r)+po[j].x;
            if(sgn(tx-ps)>0)ps=tx,c=j;
        }
        for(int j=c+1;j<i;j++)v[j]=1;
        po[i].x=ps;po[i].r=r;
        if(sgn(po[i].x+po[i].r-right)>=0)right=po[i].x+po[i].r,f=i;
    }
    for(int i=f+1;i<n;i++)v[i]=1;c=0;
    for(int i=0;i<n;i++)c+=v[i];
    printf("%d\n",c);
    for(int i=0;i<n;i++)
        if(v[i])printf("%d\n",i+1);
    return 0;
}
