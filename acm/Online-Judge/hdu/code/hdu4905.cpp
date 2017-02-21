#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long dp[3005][3005];
int cnt[3005][3005];
int pre[3005][3005];
int a[3005];
inline int gcd(int a,int b)
{
if(a<b) swap(a,b);
if(a%b)return gcd(b,a%b);
return b;
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        long long sum=0;
        for(int i=0;i<n;i++)
            scanf("%d",a+i),sum+=a[i];
        for(int i=0;i<n;i++)
        {
            pre[i][i]=a[i];
            for(int j=i+1;j<n;j++)
                pre[i][j]=gcd(pre[i][j-1],a[j]);
        }
        for(int i=0;i<n;i++)
            cnt[i][i]=i,dp[i][i]=0;
        for(int i=2;i<=n;i++)
            for(int j=0;j+i-1<n;j++)
            {
                long long te,hh=-1;
                int f,l,r,x=j,y=j+i-1;
                for(int z=cnt[x][y-1];z<=cnt[x+1][y]&&z<y;z++)
                {
                    te=dp[x][z]+dp[z+1][y];
                    if(te>hh)
                    {
                        hh=te;
                        f=z;
                    }
                }
                dp[x][y]=hh+pre[x][y];
                cnt[x][y]=f;
            }
        printf("%I64d\n",dp[0][n-1]+sum);
    }
    return 0;
}