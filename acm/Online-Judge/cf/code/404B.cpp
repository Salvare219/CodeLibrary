#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

double a,d;
inline void cal(double x)
{
    if(x<a)printf("%.6f %.6f\n",x,0.0);
    else if(x<2*a)printf("%.6f %.6f\n",a,x-a);
    else if(x<3*a)printf("%.6f %.6f\n",3*a-x,a);
    else printf("%.6f %.6f\n",0.0,4*a-x);
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%lf%lf%d",&a,&d,&n);
    double st=0.0,wei=4*a;
    for(int i=0;i<n;i++)
    {
        st+=d;
        if(st-wei>1e-7)
        {
            int bei=st/wei;
            st-=bei*wei;
        }
        cal(st);
    }
    return 0;
}
