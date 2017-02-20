#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char str[100050];
int fail[100050];
int dp[100050];
int main()
{
    int t;scanf("%d",&t);fail[0]=-1;
    while(t--)
    {
        scanf("%s",str);
        int i=0,j=-1;
        while(str[i])
        {
            while(j!=-1 && str[i]!=str[j]) j=fail[j];
            i++,j++;
            fail[i]=j;
        }
        long long ans=0;
        for(i=0;str[i];i++)
        {
            dp[i]=1;
            if(fail[i+1]) dp[i]+=dp[fail[i+1]-1];
            ans+=dp[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}