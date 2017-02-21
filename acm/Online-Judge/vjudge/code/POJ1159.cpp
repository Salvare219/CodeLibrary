#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char a[5006];
short int dp[5006][5006];
int main()
{
    int n;
    scanf("%d%s",&n,a+1);
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int l=2;l<=n;l++)
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1]+2;
            dp[i][j]=max(dp[i][j],max(dp[i][j-1],dp[i+1][j]));
        }
    printf("%d\n",n-dp[1][n]);
    return 0;
}

