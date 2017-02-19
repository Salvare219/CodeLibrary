#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<map>
int sa[150000];
const int mod=1000000007;
map<long long,long long> mp;
int pow_mod(int a,long long b)
{
    long long c=1,d=a%mod;
    while(b)
    {
        if(b&1) c=(c*d)%mod;
        b>>=1;
        d=(d*d)%mod;
    }
    return c;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,y,ma=-1;
    long long x,sum=0;
    scanf("%d%I64d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&y),sum+=y,sa[i]=y;
    for(int i=0;i<n;i++)
        mp[sa[n-1]-sa[i]]++;
    map<long long,long long>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        long long a=it->second,b=it->first;
        if(a%x==0)
        {
            long long ti=0;
            while(a%x==0) a/=x,ti++;
            mp[ti+b]+=a;
        }
        else
        {
            ma=sa[n-1]-b;
            break;
        }
    }
    if(ma<0) ma=0;
    printf("%d\n",pow_mod(x,sum-ma));
    return 0;
}
