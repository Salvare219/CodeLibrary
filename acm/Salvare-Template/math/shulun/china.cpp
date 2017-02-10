 //x=a1 mod b1
//x=a2 mod b2
//x=a3 mod b3
//……
//x=ai mod bi
//x=M1'M1a1+M2'M2a2……+Mk'MKak(mod m)   m=b1*b2*b3……bi
//Mi'Mi= 1(mod mi)    即 Mi'Mi+mi*y=1 求逆用扩展欧几里得解出 Mi'

//flag=0 无解 最后解是 r
void e_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0) x=1,y=0;
    else e_gcd(b,a%b,y,x),y-=a/b*x;
}

long long r=0,div=1,a,b,x,y,gcd;
bool flag=1;
for(int i=0;i<n;i++)
{
    scanf("%lld%lld",&b,&a); //b 是除数 a 是余数
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
if(flag) printf("%lld\n",r);
else printf("-1\n");
