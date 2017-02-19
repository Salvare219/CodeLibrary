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


int a[100];
int c[100];
bool v[130];
int sum[130];
bool dp[130];
int main()
{
    int n,k,l;
    while(~scanf("%d%d%d",&n,&k,&l))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int r=l-1;
        for(int s=(1<<k)-1,u=1<<n;s<u;)
        {
            int z=0;
            for(int i=0;i<n;i++)
                if(s&(1<<i))c[z++]=a[i];
            memset(dp,0,sizeof(dp));dp[0]=1;
            for(int i=0;i<k;i++)
                for(int j=0;j<128;j++)
                    if(dp[j])dp[j^c[i]]=1;
            int f=1;
            for(int i=l;i<=r;i++)
                if(dp[i]==0)
                {
                    f=0;
                    break;
                }
            if(f)
            {
                sort(c,c+k);
                do
                {
                    sum[0]=0;z=0;
                    for(int i=0;i<k;i++)
                        sum[i+1]=sum[i]^c[i];
                    for(int i=0;i<k;i++)
                        for(int j=0;j<=k;j++)
                        {
                            v[sum[j]^sum[i]]=1;
                            v[sum[j]^sum[i]^sum[k]]=1;
                        }
                    for(int i=l;;i++)
                        if(v[i]==0)
                        {
                            r=max(r,i-1);
                            break;
                        }
                    for(int i=0;i<k;i++)
                        for(int j=0;j<=k;j++)
                        {
                            v[sum[j]^sum[i]]=0;
                            v[sum[j]^sum[i]^sum[k]]=0;
                        }
                }while(next_permutation(c+1,c+k));
            }
            int b=s&-s;
            s=(s+b)|(((s^(s+b))>>2)/b);
        }
        if(r<l)r=0;
        printf("%d\n",r);
    }
    return 0;
}