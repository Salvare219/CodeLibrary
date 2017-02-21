#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1)
    {
        if(k==0)puts("1");
        else puts("-1");
    }
    else
    {
        if(n/2>k)puts("-1");
        else
        {
            int cnt=n/2-1,sb=1;k-=cnt;
            int ti=0;
            for(int i=1;i<=cnt;i++)
                printf("%d %d ",i*2,i*2+1),sb=2*i+1,ti+=2;
            sb++;int p=(sb+k-1)/k;
            while(__gcd(k*p,k*(p+1))!=k)p++;
            printf("%d %d ",k*p,k*(p+1));
            ti+=2;
            if(ti<n)printf("1\n");
            else putchar(10);
        }
    }
    return 0;
}