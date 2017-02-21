#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long a,b,c;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    if(b<a)
    {
        long long x=(c+b-1)/b;
        printf("%I64d %I64d\n",x,x);
    }
    else
    {
        long long mm=b/a;
        long long res=c%(mm*a);
        long long x=c/(mm*a)*mm+(res+a-1)/a;
        long long mb=(b+a-1)/a;
        long long t=x/mb;
        long long us=mb*t-mm*t;
        long long mc=mm*t;
        long long nu=x-us-mc;
        long long r1=b-mm*a;
        while(mc*a+us*r1<c)
        {
            long long z=mm,zz=mb-mm;
            if(nu>z)
            {
                mc+=z;
                nu-=z;
                z=0;
            }
            else
            {
                mc+=nu;
                z-=nu;
                nu=0;
            }
            if(nu>zz)
            {
                us+=zz;
                nu-=zz;
                zz=0;
            }
            else
            {
                us+=nu;
                zz-=nu;
                nu=0;
            }
            if(z>us)
            {
                mc+=us;
                z-=us;
                us=0;
            }
            else
            {
                mc+=z;
                us-=z;
                z=0;
            }
            t++;
            if(nu==0)
                break;
        }
        if(mc*a+us*r1<c)
        {
            long long dif=(a-r1)*mm;
            long long dif2=c-mc*a-us*r1;
            t+=(dif2+dif-1)/dif;
        }
        printf("%I64d %I64d\n",x,t);
    }
    return 0;
}
