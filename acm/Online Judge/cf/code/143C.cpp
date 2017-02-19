#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    long long a=0x3fffffff,b=0;
    a*=a;
    scanf("%d",&n);
    for(int i=1;i*i*i<=n;i++)
    {
        if(n%i) continue;
        for(int j=i;i*j*j<=n;j++)
        {
            if((n/i)%j==0)
            {
                int k=n/i/j;
                a=min(a,(long long)(i+1)*(j+2)*(k+2)-n);
                b=max(b,(long long)(i+2)*(j+2)*(k+1)-n);
            }
        }
    }
    printf("%I64d %I64d\n",a,b);
    return 0;
}


