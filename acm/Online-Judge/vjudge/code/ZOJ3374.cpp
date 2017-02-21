#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



double C[1005][1005],dp[1005][1005];
void cal()
{
    for(int i=0;i<1001;i++)
        C[i][0]=1;
    for(int i=1;i<1001;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    for(int i=0;i<1001;i++)
    {
        if(i<9) dp[i][i]=1;
        for(int j=0;j<i;j++)
            for(int k=0;k<9 && j-k>-1;k++)
                dp[i][j]+=dp[i-k-1][j-k];
    }
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m;
    cal();
    while(scanf("%d%d",&n,&m)==2)
    {
        double sum=0,ans;
        if(m<9) ans=0.0;
        else
        {
            for(int i=0;i<9;i++)
                for(int j=0;j+i<9;j++)
                    sum+=dp[n-i-j-2][m-i-j];
            ans=1-sum/C[n][m];
        }
        printf("%.8lf%%\n",100*ans);
    }
    return 0;
}
