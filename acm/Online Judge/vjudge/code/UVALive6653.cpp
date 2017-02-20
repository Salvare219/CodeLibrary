#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const long long mod=10000000000007ll;
long long fac[10050];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int l,a,b;
        scanf("%d%d%d",&l,&a,&b);
        long long ans=0;
        fac[l*l]=l*l;
        for(int i=l*l-1;i>=0;i--)
            fac[i]=fac[i+1]*i%mod;
        a=l*l-a+1;b=l*l-b+1;swap(a,b);
        for(int i=a;i<=b;i++)
        {
            ans=(ans+fac[i])%mod;
        }
        printf("Case %d: %lld\n",ti++,ans);
    }
	return 0;
}
