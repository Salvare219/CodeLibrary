#include<bits/stdc++.h>
using namespace std;


const int mod=1000000;
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        long long n,k,sum=0;
        scanf("%I64d",&n);
        for(long long i=1;i<=n;i=k+1)
        {
            k=n/(n/i);
            sum=(sum+(n/i)*(k-i+1))%mod;
        }
        printf("%d\n",(int)sum);
    }
    return 0;
}
