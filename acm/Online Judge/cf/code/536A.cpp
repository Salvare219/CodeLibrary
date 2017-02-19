#include<bits/stdc++.h>
using namespace std;


long long A,B;
long long cal(long long x)
{
    return A*x+(x-1)*x/2*B;
}
long long sum(long long l,long long r)
{
    return cal(r)-cal(l-1);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    scanf("%I64d%I64d%d",&A,&B,&n);
    while(n--)
    {
        long long l,t,m;
        scanf("%I64d%I64d%I64d",&l,&t,&m);
        if(A+B*(l-1)>t)
            printf("-1\n");
        else
        {
            long long l1=l,r1=1000000,mid;
            while(r1>l1)
            {
                mid=(r1+l1+1)>>1;
                if(A+B*(mid-1)<=t&&sum(l,mid)<=m*t)
                    l1=mid;
                else
                    r1=mid-1;
            }
            printf("%I64d\n",l1);
        }
    }
    return 0;
}
