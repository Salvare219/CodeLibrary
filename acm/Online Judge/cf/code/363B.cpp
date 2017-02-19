#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sum[200000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k,x;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&x),sum[i+1]=sum[i]+x;
    int ans=0x3fffffff,f=0;
    for(int i=0;i+k<=n;i++)
        if(sum[i+k]-sum[i]<ans) ans=sum[i+k]-sum[i],f=i;
    printf("%d\n",f+1);
    return 0;
}
