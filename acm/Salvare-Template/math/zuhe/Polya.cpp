//题意：用 k 种颜色对 n 个珠子构成的环上色，旋转翻转后相同的只算一种，求不等价的着色方案数。
//
//Burnside 定理的应用：
//
//当 n 为奇数时，有 n 种翻转，每种翻转都是以一个顶点和该顶点对边的中点对称。有 k^(n/2+1)*n 种。
//
//当 n 为偶数时，有 n 种翻转，其中一半是以两个对应顶点，另一半是以两条对边对称。有 k^(n/2+1)*n/2+k^(n/2)*n/2 种。
//
//考虑旋转 ：枚举旋转角度 360/n*i ， (0<i<=n) ，也就是一个置换 。 经过该置换 ，颜色仍保持不变的着色方案有 k^GCD(n,i) 种。
//
//一个长度为n的环 ， 每i个上同一种颜色 ，可以上多少种颜色。
//
//假设起点在 x, 则 x,x+i,x+2*i,……,x+k*i,……
//
//假设在第 t 次，第一次回到起点，则 x=(x+t*i)%n => t*i%n=0 => t=LCM(i,n)/i=n*i/GCD(n,i)/i=n/GCD(n,i)。
//
//那么可以上 n/t 种颜色，即 n/(n/GCD(n,i)) 种，所以旋转的着色方案有 k^GCD(n,i) 种。

long long cal(int a,int b)
{
    long long c=1;
    while(b--)c*=a;return c;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    while(a&&b)
    {
        if(a>b)a%=b;
        else b%=a;
    }
    return a+b;
}
int main()
{
    int s;
    while(scanf("%d",&s)&&s!=-1)
    {
        long long ans=0;
        if(s==0){puts("0");continue;}
        for(int i=0;i<s;i++)
            ans+=cal(3,gcd(s,i));
        if(s&1)ans+=s*cal(3,s/2+1);
        else ans+=s/2*(cal(3,s/2+1)+cal(3,s/2));
        printf("%lld\n",ans/s/2);
    }
    return 0;
}