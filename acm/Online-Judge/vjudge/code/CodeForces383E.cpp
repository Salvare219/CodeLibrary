#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dp[1<<24],q[1<<24];
char s[4];
int main()
{
    int n,a;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);a=0;
        for(int j=0;j<3;j++)a|=1<<(s[j]-'a');
        dp[a]++;
    }
    a=1<<24;
    for(int i=0;i<24;i++)
        for(int j=0;j<a;j++)
            if((1<<i)&j)dp[j]+=dp[(1<<i)^j];
    int ans=0;
    for(int i=0;i<a;i++)ans^=(n-dp[i])*(n-dp[i]);
    printf("%d\n",ans);
    return 0;
}
