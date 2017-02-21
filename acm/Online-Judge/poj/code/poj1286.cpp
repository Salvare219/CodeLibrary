#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long cal(int a,int b)
{
    long long c=1;
    while(b--)c*=a;return c;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    while(a&&b)
    {
        if(a>b)a%=b;
        else b%=a;
    }
    return a+b;
}
int main()
{
    int s;
    while(scanf("%d",&s)&&s!=-1)
    {
        long long ans=0;
        if(s==0){puts("0");continue;}
        for(int i=0;i<s;i++)
            ans+=cal(3,gcd(s,i));
        if(s&1)ans+=s*cal(3,s/2+1);
        else ans+=s/2*(cal(3,s/2+1)+cal(3,s/2));
        printf("%lld\n",ans/s/2);
    }
    return 0;
}
