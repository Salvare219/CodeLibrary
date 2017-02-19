#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int d[200005];
int ans[200005];
long long m[200005];
const int mod=(1ll<<31)-1;
int main()
{
    int n,k,x1,x2,x3;
    long long a,b,c;
    int sz=0;
    scanf("%d%d%d%d%I64d%I64d%I64d",&n,&k,&x1,&x2,&a,&b,&c);


    int bx1=x1, bx2=x2, bx3 ,siz=0;
    long long p=mod/k;
    for (int i=0; i<n; i++)
    {
        bx3 = (a*bx1+b*bx2+c)&mod;
        bx1=bx2;bx2=bx3;
        ans[bx3/p]++;
        siz=max(1ll*siz,bx3/p);
        m[bx3/p]=max(m[bx3/p],1ll*bx3);
    }
    int sum=0;
    for(int i=siz;i>-1;i--)
    {
        sum+=ans[i];
        if(sum>=k)
        {
            siz=i-1;
            break;
        }
    }
    if(siz==-1)p=0;
    else p=m[siz];
    while(n--)
    {
        x3=(a*x1+b*x2+c)&mod;
        x1=x2;x2=x3;
        if (p > x3)
            continue;
        x3=-x3;
        if(sz==k)
        {
            if(x3<d[0])
            {
                pop_heap(d,d+sz);
                d[sz-1]=x3;
                push_heap(d,d+sz);
            }
        }
        else
        {
            d[sz++]=x3;
            push_heap(d,d+sz);
        }
    }
    int z=0;
    while(k--)
    {
        ans[z++]=d[0];
        pop_heap(d,d+sz);sz--;
    }
    for(int i=z-1;i>-1;i--)
        printf("%d%c",-ans[i],i==0?10:' ');
    return 0;
}
