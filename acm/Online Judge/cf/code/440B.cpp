#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long a[50050],b[50050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    long long sum=0;
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i),sum+=a[i];
    for(int i=0;i<n;i++)
        b[i]=sum/n;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        long long dis=a[i]-b[i];
        ans+=abs(dis);
        a[i+1]+=dis;
    }
    printf("%I64d\n",ans);
    return 0;
}
