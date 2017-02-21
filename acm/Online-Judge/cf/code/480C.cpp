#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


const int mod=1000000007;
long long g[5050],g2[5050];
int main()
{
    int n,a,b,k;scanf("%d%d%d%d",&n,&a,&b,&k);
    g[a]++;g[a+1]--;
    for(int i=0;i<k;i++)
    {
        memset(g2,0,sizeof(g2));
        long long sum=0;
        for(int j=1;j<=n;j++)
        {
            int d=abs(j-b)-1;
            int l=max(1,j-d),r=min(n,j+d);
            sum=(sum+g[j])%mod;
            g2[l]=(g2[l]+sum)%mod;
            g2[j]=(g2[j]-sum)%mod;
            g2[j+1]=(g2[j+1]+sum)%mod;
            g2[r+1]=(g2[r+1]-sum)%mod;
        }
        memcpy(g,g2,sizeof(g));
    }
    long long ans=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=(sum+g[i])%mod;
        ans=(ans+sum)%mod;
    }
    ans+=mod;
    ans%=mod;
    printf("%d\n",(int)ans);
    return 0;
}
