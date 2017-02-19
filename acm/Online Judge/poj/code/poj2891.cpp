#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


void e_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0) x=1,y=0;
    else e_gcd(b,a%b,y,x),y-=a/b*x;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        long long r=0,div=1,a,b,x,y,gcd;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&b,&a);
            e_gcd(div,b,x,y);
            if(flag)
            {
                gcd=div*x+b*y;
                if((r-a)%gcd) flag=0;
                else
                {
                    x=(a-r)/gcd*x%(b/gcd);
                    r=(div*x+r)%(div/gcd*b);
                    if(r<0) r+=div/gcd*b;
                    div*=b/gcd;
                }
            }
        }
        if(flag) printf("%lld\n",r);
        else printf("-1\n");
    }
    return 0;
}




