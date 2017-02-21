#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


int main()
{
    long long a,b,c,k,s,i;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)==3)
    {
        s=k=0;
        k+=min(a,2ll)+min(b,2ll)+min(c,2ll);
        for(i=0;i<k;i++)
            s+=i;
        s+=((a+b+c)-k)*k;
        printf("%I64d\n",s);
    }
    return 0;
}
