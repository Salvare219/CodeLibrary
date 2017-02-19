#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

double pi=acos(-1.0);
double cal(double a,double h)
{
    double te=a*a*a*a,s=h*h+a*a;
    double x=sqrt(a*a-te/s);
    return x;
}
int main()
{
//    freopen("1.txt","r",stdin);
    double s;scanf("%lf",&s);
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            if(fabs(s-cal(1.0*i,1.0*j/2))<1e-6)
            {
                printf("%d %d\n",j,i);
                return 0;
            }
        }
    return 0;
}
