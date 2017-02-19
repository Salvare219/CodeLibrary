#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int pre[1000500];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int sum=0,x;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]^i;
    for(int i=0;i<n;i++)
        scanf("%d",&x),sum^=x;
    for(int i=2;i<=n;i++)
    {
        int div=(n+1)/i,res=(n+1)%i;
        if(div&1)sum^=pre[i-1];
        if(res)sum^=pre[res-1];
    }
    printf("%d\n",sum);
    return 0;
}
