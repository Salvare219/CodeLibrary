#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double E[1005][1005];
int main()
{
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        for(int i=1;i<=n;i++)E[i][0]=E[i-1][0]+1.0*n/i;
        for(int i=1;i<=s;i++)E[0][i]=E[0][i-1]+1.0*s/i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=s;j++)
            {
                double te=s*i+n*j-i*j;
                E[i][j]=(E[i-1][j-1]*i*j+E[i][j-1]*(n-i)*j+E[i-1][j]*i*(s-j)+n*s)/te;
            }
        printf("%.4f\n",E[n][s]);
    }
    return 0;
}
