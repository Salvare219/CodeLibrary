#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long l,r;
        scanf("%I64d%I64d",&l,&r);
        long long cnt=0,sb=0;
        for(long long i=63;i>-1;i--)
        {
            long long x=(1ll<<i)&l,y=(1ll<<i)&r;
            if(x==y)
            {
                cnt+=x;
                if(x)sb++;
                continue;
            }
            sb+=i;
            if(sb>=__builtin_popcountll(r))
                cnt+=(1ll<<i)-1;
            else cnt=r;
            break;
        }
        printf("%I64d\n",cnt);
    }
    return 0;
}
