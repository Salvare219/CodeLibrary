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

int dp[1000050];
void cal(int n)
{
    dp[0]=0;
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        int c=i,b;
        while(c)
        {
            b=c%10;
            if(i-b>=0) dp[i]=min(dp[i-b]+1,dp[i]);
            c/=10;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    cal(n);
    printf("%d\n",dp[n]);
}




/*
map<int,int> p;
int num[400000];
long long sum[400000];
int a[400000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",num+i);
        p[num[i]]=i;
        sum[i+1]=sum[i]+max(0,num[i]);
    }
    long long ans=0;
    int fl;
    for(int i=0;i<n;i++)
    {
        if(ans<sum[p[num[i]]+1]-sum[i])
        {
            ans=sum[p[num[i]]+1]-sum[i];
            fl=i;
        }
    }
    printf("%I64d ",ans);
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(i<fl) a[k++]=i;
        else if(i>p[num[fl]]) a[k++]=i;
        else
        {
            if(num[i]<0) a[k++]=i;
        }
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++)
        if(i) printf(" %d",a[i]+1);
        else printf("%d",a[i]+1);
    return 0;
}*/
