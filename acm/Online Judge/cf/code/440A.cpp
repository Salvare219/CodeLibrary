#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    long long sum=1ll*n*(n+1)/2,d=0;
    for(int i=1;i<n;i++)
        scanf("%d",&x),d+=x;
    printf("%I64d\n",sum-d);
    return 0;
}
