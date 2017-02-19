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


int mod=1000000009;
long long pow_mod(int a,int b)
{
    long long c=a,d=1;
    while(b)
    {
        if(b&1) d=(d*c)%mod;
        b>>=1;
        c=(c*c)%mod;
    }
    return d;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a=n/k,b=n%k,c,fu;
    if(m<=b) printf("%d\n",m);
    else
    {
        m-=b;
        fu=b;
        b=m/a;
        c=m%a;
        if(b<k-1) printf("%d\n",m+fu);
        else
        {
            long long sum=0;
            if(b==k)
            {
                sum=(pow_mod(2,a+1)-2+mod)%mod*k%mod+fu;
                printf("%I64d\n",sum%mod);
            }
            else
            {
                sum=(pow_mod(2,c+1)-2+mod)%mod*k%mod+(long long)(k-1)*(a-c)%mod+fu;
                printf("%I64d\n",sum%mod);
            }
        }
    }
    return 0;
}
