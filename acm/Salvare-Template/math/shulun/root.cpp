Ver 3.0

struct Root
{
    int prim[230000],k;
    bool vis[1000050];
    void cal()
    {
        for(int i=2;i<1000005;i++)
        {
            if(vis[i]==0) prim[k++]=i;
            for(int j=0;j<k && prim[j]*i<1000005;j++)
            {
                vis[prim[j]*i]=1;
                if(i%prim[j]==0) break;
            }
        }
    }
    int fac[40],fk;
    void getFactor(long long c)
    {
        fk=0;
        for(int i=0;i<k&&(long long)prim[i]*prim[i]<=c;i++)
            if(c%prim[i]==0)
            {
                fac[fk++]=prim[i];
                do c/=prim[i];
                while(c%prim[i]==0);
            }
        if(c!=1)
            fac[fk++]=c;
    }
    long long pow_mod(long long a,long long b,long long mod)
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
    int getPriRoot(long long p)
    {
        if(p==2)return 1;
        long long phi=p-1;
        getFactor(phi);
        for(int g=2;g<p;++g)
        {
            bool f=1;
            for(int i=0;f&&i<fk;i++)
                if(pow_mod(g,phi/fac[i],p)==1)
                    f=0;
            if(f)
                return g;
        }
    }
}g;