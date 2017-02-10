//位反转
inline int reverse_bits(int x)
{
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

inline LL reverse_bits(LL x)
{
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}

//LCIS  = =

memset(dp,0,sizeof(dp));
for(int i=1;i<=n;i++)
    for(int j=1,k=0;j<=m;j++)
    {
        if(a[i]==b[j])dp[j]=dp[k]+1;
        else if(a[i]>b[j]&&dp[j]>dp[k])k=j;
    }
int ans=0;
for(int i=1;i<=m;i++)
    ans=max(ans,dp[i]);

	
//回文序列
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i] = 1;
    for(int l=1;l<=n;l++)
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            dp[i][j]=max(dp[i+1][j-1]+(a[i]==a[j]?2:0),max(dp[i+1][j],dp[i][j-1]));
        }
	

//dp求和
    a=1<<24;
    for(int i=0;i<24;i++)
        for(int j=0;j<a;j++)
            if((1<<i)&j)dp[j]+=dp[(1<<i)^j];
			
//枚举子集

for(int i=(s-1)&s;i;i=(i-1)&s)  //真子集

//枚举长为n含k个1的01串
int n=5,k=3;
for(int s=(1<<k)-1,u=1<<n;s<u;)
{
	//do it;
	int b=s&-s;
	s=(s+b)|(((s^(s+b))>>2)/b);
}
