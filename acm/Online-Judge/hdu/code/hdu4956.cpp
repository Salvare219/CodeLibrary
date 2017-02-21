#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int ok1(long long x)
{
    return x%11==3;
}
int ok2(long long x)
{
    int sum=0,cnt=1;
    while(x)
    {
        if(cnt&1)sum+=x%10;
        else sum-=x%10;
        x/=10;cnt++;
    }
    return sum==3;
}
int main()
{
    //freopen("1.txt","r",stdin);
    long long l,r;
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&l,&r);
        long long c=-1;
        for(long long i=l;i<=r;i++)
        {
            int a=ok1(i);
            int b=ok2(i);
            if(a==b);
            else
            {
                c=i;
                break;
            }
        }
        printf("%I64d\n",c);
    }
    return 0;
}