#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int aa[20],bb[20];
void e_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0) x=1,y=0;
    else e_gcd(b,a%b,y,x),y-=a/b*x;
}
int main()
{
    int t ;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        long long r=0,div=1,a,b,x,y,gcd;
        bool flag=1;
        for(int i=0;i<m;i++)
            scanf("%d",aa+i);
        for(int i=0;i<m;i++)
            scanf("%d",bb+i);
        for(int i=0;i<m;i++)
        {
            b=aa[i];a=bb[i];
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
        if(r==0) r=div;
        if(n<r) flag=0;
        if(flag) printf("%d\n",(n-r)/div+1);
        else printf("0\n");
    }
    return 0;
}




