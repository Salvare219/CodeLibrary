#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long dp[500];
long long cal(long long n)
{
    if(n==0)return 0;
    int i=60;
    long long sum=0,ex=0,sb=1;
    while(((1ll<<i)&n)==0)i--;
    for(int j=0;j<i;j++)sb*=2;
    for(;i>-1;i--,sb/=2)
        if((1ll<<i)&n)
        {
            sum+=dp[i]+ex*sb;ex++;
        }
    return sum+ex;
}
int main()
{
    long long a,b,sb=2;dp[1]=1;
    for(int i=2;i<60;i++)
        dp[i]=2*dp[i-1]+sb,sb*=2;
    while(scanf("%lld%lld",&a,&b)==2)
        printf("%lld\n",cal(b)-cal(a-1));
    return 0;
}
