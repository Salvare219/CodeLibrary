#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int a[100050];
char s[100050];
long long sum[100050];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),sum[i+1]=sum[i]+a[i];
    scanf("%s",s);
    int h=0;
    long long ans=0,now=0;
    for(int i=n-1;i>-1;i--)
        if(s[i]=='1')
        {
            ans=max(ans,now+sum[i]);
            now+=a[i];
        }
    ans=max(ans,now);
    printf("%I64d\n",ans);
    return 0;
}

