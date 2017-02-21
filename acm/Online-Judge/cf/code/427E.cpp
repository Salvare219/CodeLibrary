#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long a[1000005];
inline int Int()
{
	int a=0;char c=getchar(),s=0;
	while(c<'0')s=c,c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return s!='-'?a:-a;
}
long long sum[1000005],sum2[1000005];
int main()
{
//    freopen("1.txt","r",stdin);
    int n=Int(),m=Int();
    for(int i=0;i<n;i++)
        a[i]=Int();
    for(int i=0;i<n;i+=m)
        sum[i]=a[i];
    for(int i=n-1;i>-1;i-=m)
        sum2[i]=a[i];
    for(int i=n-2;i>-1;i--)
        sum[i]+=sum[i+1];
    for(int i=1;i<n;i++)
        sum2[i]+=sum2[i-1];
    long long te,ans=1<<30;
    ans*=ans;
    for(int i=0;i<n;i++)
    {
        te=a[i]*((i+m-1)/m)-(sum[0]-sum[i]);
        te+=(sum2[n-1]-sum2[i])-a[i]*((n-i-1+m-1)/m);
        ans=min(ans,2*te);
    }
    printf("%I64d\n",ans);
    return 0;
}
