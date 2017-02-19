#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


long long sum[1000000];
int main()
{
    freopen("aztec.in","r",stdin);
    freopen("aztec.out","w",stdout);
    sum[0]=1;
    int k=0;
    for(int i=1;sum[i-1]<2000000000;i++)
    {
        sum[i]=sum[i-1]+1ll*i*i+1ll*(i+1)*(i+1);
        k++;
    }
    int n;scanf("%d",&n);
    printf("%d\n",upper_bound(sum,sum+k,n)-sum);
    return 0;
}
