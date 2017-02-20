#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,p;scanf("%d%d%d",&n,&m,&p);
        if(m>=(n-1)/2)
        {
            if(p==n)printf("%d\n",m-(n-1)/2);
            else if(p%2^n%2) puts("0");
            else puts("1");
        }
        else
        {
            m++;m<<=1;
            if(n>=m+2)
            {
                int s=4;
                while(s-2+m<=n)s<<=1;
                s>>=1;s=s-2+m;
                if(p>s) puts("Thrown");
                else puts("0");
            }
            else
            {
                n--;
                if(p==n+1) puts("Thrown");
                else if(p==n) puts("0");
                else if(p%2^n%2) puts("0");
                else puts("1");
            }
        }
    }
    return 0;
}
