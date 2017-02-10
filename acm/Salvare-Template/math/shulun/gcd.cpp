//统计 x=[1,a],y=[1,b],gcd(x,y)=k 的对数  这里保证类似 (1,3),(3,1) 只算一次

法一
//枚举 x ,分解素因子，通过容斥原理求出 [1,b] 与 x 互素的个数

int dfs(int b,int s) //容斥原理
{
    if(b<2) return 0;
    int ans=0;
    while(s<fk)
    {
        ans+=b/fac[s]-dfs(b/fac[s],s+1);
        s++;
    }
    return ans;
}

long long ans;
if(k==0) ans=0;
else
{
    a/=k;b/=k;
    if(a>b) swap(a,b);
    ans=0;
    for(int i=1;i<=a;i++)
    {
        fk=0;k=i;
        for(int j=0;vis[k];j++)
            if(k%prim[j]==0)
            {
                fac[fk++]=prim[j];
                while(k%prim[j]==0) k/=prim[j];
            }
        if(k>1) fac[fk++]=k;
        ans+=b-i+1-(dfs(b,0)-dfs(i-1,0));
    }
}

法二
//fac[i] 表示 gcd(x,y)=i 的对数 利用 fac[i]=(n/i)*(m/i)-fac[2*i]-fac[3*i] ..去重
if(k==0) ans=0;
else
{
    long long n,m;
    a/=k;b/=k;
    if(a>b) swap(a,b);
    fac[1]=0;
    for(int i=a;i>0;i--)
    {
        n=a/i,m=b/i;
        n=(2*m-n+1)*n/2;
        for(int j=i+i;j<=a;j+=i)
            n-=fac[j];
        fac[i]=n;
    }
    ans=fac[1];
}


法三
//莫比乌斯反演 (还有分块优化)
//定义
//F(n) = sigma (G(d))   d | n
//那么 G(n) = sigma (F(d) * miu (n / d))  d | n
//还有另外一个表达形式
//F(n) = sigma (G(d))  n | d
//G(n) = sigma (F(d) * miu (d / n))  n | d

int main()
{
    for(int i=1;i<100001;i++)mu[i]+=mu[i-1];
    int a,b,k;
    if(k==0)printf("Case %d: 0\n",ti++);
    else
    {
        a/=k;b/=k;
        if(a>b)swap(a,b);
        long long sum=0,sum2=0;
        for(int i=1;i<=a;i=k+1)
        {
            k=min(a/(a/i),b/(b/i));
            sum+=1ll*(mu[k]-mu[i-1])*(a/i)*(b/i);
            sum2+=1ll*(mu[k]-mu[i-1])*(a/i)*(a/i);
        }
        printf("%I64d\n",sum-sum2/2);
    }
    return 0;
}