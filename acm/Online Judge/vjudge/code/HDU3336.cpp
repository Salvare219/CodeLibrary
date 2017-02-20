#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int nex[200005],dp[200005];
char ori[200005];
int main()
{
 //   freopen("2.txt","r",stdin);
    int t;
    scanf("%d",&t);
    nex[0]=-1;
    while(t--)
    {
        int n;
        scanf("%d%s",&n,ori);
        int i=0,j=-1;
        while(ori[i])
        {
            while(j!=-1 && ori[i]!=ori[j]) j=nex[j];
            i++;j++;
            nex[i]=j;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            dp[i]=(dp[nex[i]]+1)%10007;
            ans=(ans+dp[i])%10007;
        }
        printf("%d\n",ans);
    }
    return 0;
}