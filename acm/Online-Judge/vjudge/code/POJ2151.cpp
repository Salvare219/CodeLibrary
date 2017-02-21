#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

double p[1005][35],dp[35];
int main()
{
    int m,t,n,i,j,z;
    while(scanf("%d%d%d",&m,&t,&n)&&t)
    {
        for(i=0;i<t;i++)
            for(j=0;j<m;j++)
                scanf("%lf",&p[i][j]);
        double p1=1.0,p2=1.0;
        for(i=0;i<t;i++)
        {
            memset(dp,0,sizeof(dp));dp[0]=1.0;
            double t1=0,t2=0;
            for(z=0;z<m;z++)
                for(j=m-1;j>-1;j--)
                {
                    dp[j+1]+=dp[j]*p[i][z];
                    dp[j]=dp[j]*(1.0-p[i][z]);
                }
            for(j=1;j<=m;j++)t1+=dp[j];
            for(j=n;j<=m;j++)t2+=dp[j];
            if(abs(t1)<1e-6){p1=0.0;break;}
            p1*=t1;p2*=(t1-t2)/t1;
        }
        printf("%.3f\n",p1*(1-p2));
    }
    return 0;
}
