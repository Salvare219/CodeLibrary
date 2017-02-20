#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long a,b;
bool cal(long long k1,long long k2)
{
    long long l1=k2*a-k1*b,l2=b*b+a*a,x,y;
    if(l2!=0)
    {
        if(l1%l2==0)
        {
            y=l1/l2;x=k1+b*y;
            if(a!=0)
            {
                if(x%a==0)
                {
                    return 1;
                }
            }
            else
            {
                if(b!=0)
                {
                    if(k2%b==0)return 1;
                }
            }
        }
    }
    else
    {
        if(abs(k1)==abs(k2))
        {
            if(k1%a==0)
            {
                if(k1%a>=0)return 1;
            }
        }
    }
    return 0;
}
int main()
{
    long long nx,ny,tx,ty;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&nx,&ny,&tx,&ty,&a,&b);
    if(tx==nx&&ty==ny){puts("YES");return 0;}
    if(tx==-ny&&ty==nx){puts("YES");return 0;}
    if(tx==-nx&&ty==-ny){puts("YES");return 0;}
    if(tx==ny&&ty==-nx){puts("YES");return 0;}
    if(a==0&&b==0)puts("NO");
    else
    {
        if(cal(tx-nx,ty-ny)||cal(tx+ny,ty-nx)||cal(tx+nx,ty+ny)||cal(tx-ny,ty+nx))puts("YES");
        else puts("NO");
    }
    return 0;
}
