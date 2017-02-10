//FNT  有点慢 = =
//g 为 mod 的原根

//1004535809 3
//211812353 3
//10000000025100289 22
//11000000009994241 17
//100000000135659521 3

const int mod=211812353,g=3;
int _g[30],_ig[30];
long long invl;
int pow_mod(long long a,int b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=c*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
void init()
{
    for(int i=0;i<30;i++)
    {
        _g[i]=pow_mod(g,(mod-1)/(1<<i));
        _ig[i]=pow_mod(_g[i],mod-2);
    }
}
void FNT(int F[],int len,int f)
{
    int i,j,k,cnt=1;
    long long x,y,w=1,wn;
    for(i=1,j=0,k=0;i<=len;i++)
    {
        if(j<k) swap(F[j],F[k]);
        j^=i&-i;
        k^=len/(i&-i)>>1;
    }
    for(i=1;i<len;i<<=1)
    {
        wn=f?_g[cnt++]:_ig[cnt++];
        for(j=0;j<len;j+=i<<1,w=1)
            for(k=j;k<j+i;k++,w=w*wn%mod)
            {
                x=F[k];y=w*F[k+i]%mod;
                F[k]=x+y;F[k+i]=x-y;
                if(F[k]>=mod)F[k]-=mod;
                if(F[k+i]<0)F[k+i]+=mod;
            }
    }
    if(!f)
        for(i=0;i<len;i++)F[i]=F[i]*invl%mod;
}
int a[150000],b[150000];
void conv(int ca[],int l1,int cb[],int l2,int c[],int &l)
{
    l=1<<(32-__builtin_clz(l1+l2));
    init();invl=pow_mod(l,mod-2);
    for(int i=0;i<l;i++)
    {
        a[i]=i<l1?ca[i]:0;
        b[i]=i<l2?cb[i]:0;
    }
    FNT(a,l,1);FNT(b,l,1);
    for(int i=0;i<l;i++)a[i]=(long long)a[i]*b[i]%mod;
    FNT(a,l,0);
    for(int i=0;i<l;i++)c[i]=a[i];
}