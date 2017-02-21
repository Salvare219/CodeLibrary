#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int dp[100050][2];
int main()
{
//    freopen("1.txt","r",stdin);
    dp[0][1]=0;
    dp[0][0]=1;
    for(int i=1;i<100005;i++)
    {
        dp[i][0]=(dp[i-1][1]+dp[i-1][0])%10007;
        dp[i][1]=dp[i-1][0];
    }
    int n;
    while(scanf("%d",&n)==1) printf("%d\n",(dp[n][1]+dp[n][0])%10007);
    return 0;
}

