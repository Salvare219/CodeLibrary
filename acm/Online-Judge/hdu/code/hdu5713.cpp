#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;


const int mod=1000000009;
bool mat[14][14];
int dp[1<<14];
int dp3[1<<14];
int dp2[15][1<<14];
int ex[500],ey[500];
inline long long pow_mod(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=a*c%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
inline int Int()
{
    int a=0;char c=getchar();
    while(c<'0')c=getchar();
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
    return a;
}
int inv[20];
int main()
{
    int t=Int(),ti=1;
    long long fz=1;
    for(int i=1;i<20;i++)
    {
        fz=fz*i%mod;
        inv[i]=pow_mod(fz,mod-2);
    }
    while(t--)
    {
        int n,m,k;
        n=Int();
        m=Int();
        k=Int();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j]=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            x=Int()-1;y=Int()-1;
            mat[x][y]=mat[y][x]=1;
            ex[i]=x;ey[i]=y;
        }
        int lim=1<<n;
        for(int j=0;j<lim;j++)
            dp[j]=0;
        for(int i=0;i<n;i++)
            dp[1<<i]=1;
        long long we=1;
        for(int i=0;i<m;i++)
        {
            int x=ex[i],y=ey[i];
            if(x==y)we=we*2%mod;
            else
            {
                //for(int i=0;i<lim;i++)
                //    dp3[i]=0;
                int mm=(1<<x)|(1<<y);
                int z=(lim-1)^mm;
                for(int f=z;;)
                {
                    int h=f|mm;
                    dp[h]=dp[h]+dp[h];
                    if(dp3[h]>=mod)dp3[h]-=mod;
                    for(int f2=f;;)
                    {
                        int s1=f2|(1<<x),s2=(f^f2)|(1<<y);
                        if(dp[s1]==0||dp[s2]==0)
                        {
                            if(f2==0)
                                break;
                            f2=(f2-1)&f;
                            continue;
                        }
                        dp[h]=(dp[h]+(long long)dp[s1]*dp[s2])%mod;
                        if(f2==0)
                            break;
                        f2=(f2-1)&f;
                    }
                    if(f==0)
                        break;
                    f=(f-1)&z;
                }
                //for(int i=0;i<lim;i++)
                //{
                //    dp[i]=dp[i]+dp3[i];
                //    if(dp[i]>=mod)dp[i]-=mod;
                //}
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<lim;j++)
                dp2[i][j]=0;
        for(int i=1;i<lim;i++)
            dp2[1][i]=dp[i];
        for(int h=2;h<=k;h++)
        {
            for(int s=0;s<lim;s++)
            {
                for(int f=s;f;f=(f-1)&s)
                {
                    if(dp2[h-1][f^s]==0||dp[f]==0)continue;
                    dp2[h][s]=(dp2[h][s]+(long long)dp2[h-1][f^s]*dp[f])%mod;
                }
            }
        }
        long long ans=dp2[k][lim-1]*we%mod;
        ans=ans*inv[k]%mod;
        printf("Case #%d:\n%d\n",ti++,(int)ans);
    }
    return 0;
}