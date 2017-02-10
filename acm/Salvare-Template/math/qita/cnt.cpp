//O(n*m)
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
long long C(int a)
{
    long long temp=a;
    return temp*(temp-1)*(temp-2)/6;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        m++;n++;
        long long ans=C(n*m)-C(n)*m-C(m)*n,temp;
        m--;n--;
        for(int i=2;i<=n;i++)
            for(int j=2;j<=m;j++)
            {
                temp=gcd(i,j);
                ans-=(temp-1)*(n-i+1)*(m-j+1)*2;
            }
        printf("%lld\n",ans);
    }
    return 0;
}