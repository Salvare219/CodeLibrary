#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


long long C[2000005];
long long mod=1000000007;
void e_gcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return ;
	}
	e_gcd(b,a%b,y,x);
	y-=a/b*x;
}
void cal(int n)
{
    long long inv,d;
    C[0]=1;
    for(int i=1;i<=n;i++)
    {
        e_gcd(i,mod,inv,d);
        inv=(inv%mod+mod)%mod;
        C[i]=(C[i-1]*(((n-i+1)*inv)%mod))%mod;
    }
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    cal(n);
    int p;
    long long temp,ans=0;
    for(long long i=0;i<=n;i++)
    {
        temp=a*(n-i)+b*i;
        bool flag=1;
        while(temp)
        {
            p=temp%10;
            if(p!=a && p!=b)
            {
                flag=0;
                break;
            }
            temp/=10;
        }
        if(flag)
        {
            ans=(ans+C[i])%mod;
        }
    }
    printf("%I64d\n",ans%mod);
    return 0;
}
