#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int gcd(int a,int b)
{
    int c=a%b;
    while(c)
    {
        a=b;b=c;
        c=a%b;
    }
    return b;
}
int main()
{
 //   freopen("1.txt","w",stdout);
    int p,t,ti;
    scanf("%d",&ti);
    while(ti--)
    {
        scanf("%d%d",&p,&t);
        t%=p-1;
        if(t==0) printf("1\n");
        else printf("%d\n",(p-1)/gcd(p-1,t));
    }
    return 0;
}


/*
int p,t;
int pow_mod(int a,int b)
{
    long long c=1,d=a%p;
    while(b)
    {
        if(b&1) c=(c*d)%p;
        b>>=1;
        d=(d*d)%p;
    }
    return c;
}
int prim[44]={2,3,5,7,11,13,17,19,23,29,31,0};
int main()
{
    freopen("2.txt","w",stdout);
    for(int i=0;prim[i];i++,putchar(10))
        for(int j=1;j<prim[i];j++)
    {
        t=j;p=prim[i];
        t%=(p-1);
        bool vis[1000]={0};
        for(int i=1;i<p;i++)
        {
            vis[pow_mod(i,t)]=1;
        }
        int sum=0;
        for(int i=1;i<p;i++)
            sum+=vis[i];
        printf("%d ",sum);
    }
    return 0;
}*/

