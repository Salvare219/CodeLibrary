
//取模版本
int a[305][305];
int mod=10007;
int pow_mod(int a,int b)
{
    int c=1;
    a%=mod;
    while(b)
    {
        if(b&1) c=(c*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return c;
}
int det(int n)
{
    int i,j,k,ans=1,div=1;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i;j<n;j++)
            if(a[j][i])
            {
                k=j;
                break;
            }
        if(a[k][i]==0) return 0;
        if(k!=i) for(ans=mod-ans,j=i;j<n;j++) swap(a[i][j],a[k][j]);
        ans=(a[i][i]*ans)%mod;
        for(j=i+1;j<n;j++)
            if(a[j][i])
            {
                div=(div*a[i][i])%mod;
                for(k=n-1;k>=i;k--)
                    a[j][k]=((a[j][k]*a[i][i]-a[i][k]*a[j][i])%mod+mod)%mod;
            }
    }
    ans=(ans*pow_mod(div,mod-2))%mod;
    return ans;
}

//gcd版本
long long a[305][305];
long long det(int n)
{
    int i,j,k,pa,pb;
    long long ans=1,pt;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i;j<n;j++)
            if(a[j][i])
            {
                k=j;
                break;
            }
        if(a[k][i]==0) return 0;
        if(k!=i)for(ans=-ans,j=i;j<n;j++) swap(a[i][j],a[k][j]);
        for(j=i+1;j<n;j++)
            if(a[j][i])
            {
                if(a[i][i]>a[j][i])pa=i,pb=j;
                else pa=j,pb=i;
                while(a[pb][i])
                {
                    swap(pa,pb);
                    pt=a[pb][i]/a[pa][i];
                    for(k=i;k<n;k++)
                        a[pb][k]-=a[pa][k]*pt;
                }
                if(i!=pa)for(ans=-ans,k=i;k<n;k++)swap(a[i][k],a[j][k]);
            }
        ans*=a[i][i];
    }
    return ans;
}
