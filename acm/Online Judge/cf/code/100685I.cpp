#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    __int64 A,B,a,b;
    while(scanf("%I64d%I64d",&A,&B)==2)
    {
        scanf("%I64d%I64d",&a,&b);
        __int64 ans=(A/a)*(B/b);
        __int64 na=B/b,nb=A/a;
        __int64 a2=A%a,b2=B%b,t,r;
        bool l=0;
        if(a2)
        {
            t=na/(a/a2);
            r=na%(a/a2);
            if(r)
            {
                t++;
                l=1;
            }
            ans+=t;
        }
        if(b2)
        {
            t=nb/(b/b2);
            r=nb%(b/b2);
            if(r)
            {
                t++;
                l=1;
            }
            ans+=t;
        }
        if(a2&&b2&&!l) ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}
