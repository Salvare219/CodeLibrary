//欧拉函数 与 N 互质的个数
//预处理
//Ver 2.3;
int prim[100005],phi[100005];
int pk;
bool vis[100005];
void cal()
{
    phi[1]=1;
    for(int i=2;i<100001;i++)
    {
        if(!vis[i]) prim[pk++]=i,phi[i]=i-1;
        for(int j=0;j<pk && i*prim[j]<100001;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]) phi[i*prim[j]]=phi[i]*(prim[j]-1);
            else
            {
                phi[i*prim[j]]=phi[i]*prim[j];
                break;
            }
        }
    }
}
//Ver 1.0;
void cal()
{
	phi[1]=1;
	for(int i=2;i<5000005;i++)
	   if(!phi[i])
		   for(int j=i;j<5000005;j+=i)
			{
				if(!phi[j])phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
}
//直接算  可先筛素数来优化
int phi(int s)
{
	int ret=1;
	for(int i=2;i*i<=s;i++)
		if(s%i==0)
		{
			s/=i,ret*=i-1;
			while(s%i==0) s/=i,ret*=i;
		}
    if(s>1) ret*=s-1;
    return ret;    //n 的欧拉数
}
ans=N*phi(N)/2      //求小于 N 的与 N 互质的数的和
phi(p^k)=p^k-p^(k-1)=(p-1)*p^(k-1)
phi(n)=phi(p1^a1)*phi(p2^a2)*phi(p3^a3)*...*phi(pn^an)     


//莫比乌斯函数
//预处理
int prim[100005],mu[100005];
int pk;
bool vis[100005];
void cal()
{
    mu[1]=1;
    for(int i=2;i<100001;i++)
    {
        if(!vis[i]) prim[pk++]=i,mu[i]=-1;
        for(int j=0;j<pk && i*prim[j]<100001;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]) mu[i*prim[j]]=-mu[i];
            else
            {
                mu[i*prim[j]]=0;
                break;
            }
        }
    }
}
//直接算  可先筛素数来优化
int mu(int s)
{
    int ret=1;
    for(int i=2;i*i<=s;i++)
        if(s%i==0)
        {
            s/=i,ret=-ret;
            if(s%i==0)return 0;
        }
    if(s>1) ret=-ret;
    return ret;
}
//F(n) = sigma (G(d))   d | n
//那么 G(n) = sigma (F(d) * miu (n / d))  d | n
//还有另外一个表达形式
//F(n) = sigma (G(d))  n | d
//G(n) = sigma (F(d) * miu (d / n))  n | d