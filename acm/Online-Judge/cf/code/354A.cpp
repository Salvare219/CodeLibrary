#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


long long pre[100050];
int main()
{
 //   freopen("1.txt","r",stdin);
    long long n,l,r,q1,q2,sum=0;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&l,&r,&q1,&q2);
    long long temp;
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&temp);
        pre[i+1]=pre[i]+temp;
        sum+=temp;
    }
    long long a,b,ex;
    long long ans=0x3fffffff;
    ans*=ans;
    for(int i=0;i<=n;i++)
    {
        a=pre[i]*l;b=(sum-pre[i])*r;
        if(n-i>i) ex=q2*(n-i-1-i);
        else if(n-i==i) ex=0;
        else ex=q1*(i-n+i-1);
        ans=min(ans,a+b+ex);
    }
    printf("%I64d\n",ans);
    return 0;
}

