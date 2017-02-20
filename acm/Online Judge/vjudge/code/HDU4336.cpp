#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int n;
double dp[1<<20];
double p[55];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lf",p+i);
        for(int i=1;i<(1<<n);i++)
        {
            double sum=0.0,sump=0.0;
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                {
                    sump+=p[j];
                    sum+=p[j]*dp[i^(1<<j)];
                }
            dp[i]=(1.0+sum)/sump;
        }
        printf("%.8f\n",dp[(1<<n)-1]);
    }
    return 0;
}
