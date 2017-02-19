#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double c[400000];
double p[400000];
int main()
{
    int m,n;
    double r;
    scanf("%d%d%lf",&m,&n,&r);
    for(int i=0;i<m;i++)
        scanf("%lf",c+i);
    for(int i=0;i<n;i++)
        scanf("%lf",p+i);
    int k;
    double las=c[0],pos,ans=0.0;
    double con=sqrt(r*r-1.0);
    for(int i=0;i<n;i++)
        if(las>p[i])
        {
            pos=p[i]+con;
            pos=*(upper_bound(c,c+m,pos)-1);
            if(pos>las);
            else
            {
                ans+=las-pos;
                las=pos;
            }
        }
        else
        {
            pos=p[i]-con;
            pos=*lower_bound(c,c+m,pos);
            if(pos<las);
            else
            {
                ans+=pos-las;
                las=pos;
            }
        }
    printf("%.8f\n",ans);
    return 0;
}
