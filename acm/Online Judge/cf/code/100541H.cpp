#include<bits/stdc++.h>
using namespace std;


long long n,m;
/*
inline int cal(int x,int a,int b)
{
    return a*b*(2*x+a-1+(b-1)*m)/2;
}*/
inline long long cal(long long f,long long x,long long y)
{
    long long z=x-1+(y-1)*m;
    if((f-z)&1)return -1;
    else return (f-z)/2;
}
inline bool ok(int x,int y)
{
    return x<=n&&y<=m;
}
long long sum[555][555];
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        long long l;
        scanf("%I64d%I64d%I64d",&n,&m,&l);
        long long lim=(n-1)*m+m-1;
        long long ans=-1;
        long long u=sqrt(8*l+1)+5;
        for(long long i=1;i<=u;i++)
            if((2*l)%i==0)
            {
                long long f=2*l/i;
                for(long long j=1;j*j<=i;j++)
                    if(i%j==0)
                    {
                        long long x=j,y=i/j;
                        long long h1=cal(f,x,y);
                        long long h2=cal(f,y,x);
                        if(h1>=0&&h1<=lim&&ok(h1/m+y,h1%m+x))
                        {
                            ans=i;
                            break;
                        }
                        if(h2>=0&&h2<=lim&&ok(h2/m+x,h2%m+y))
                        {
                            ans=i;
                            break;
                        }
                    }
                if(ans!=-1)
                    break;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
