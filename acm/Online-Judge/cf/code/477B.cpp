#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    long long sb=1ll*(n-1)*6+1+1+2+1;
    printf("%I64d\n",sb*k);
    for(long long i=0;i<n;i++)
    {
        long long a=i*6+1,b=a+1,c=b+1,d=c+2;
        printf("%I64d %I64d %I64d %I64d\n",k*a,k*b,k*c,k*d);
    }
    return 0;
}




