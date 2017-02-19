#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    long long n;scanf("%I64d",&n);
    long long c=2;
    long long cnt=0,f=1;
    while(c<=n)
    {
        if(n>=c)
        {
            long long res=n-c;
            if(res%3==0)
                cnt++;
        }
        f++;
        c=c+2*f+f-1;
        //printf("%I64d\n",c);
    }
    printf("%I64d\n",cnt);
    return 0;
}
