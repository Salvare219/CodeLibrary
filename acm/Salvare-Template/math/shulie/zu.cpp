//卡特兰数	
h[n]=∑h[i]*h[n-1-i]  
	h[n]=c[2*n][n]/(n+1);
h(n)=c(2n,n)-c(2n,n+1);
h(n)=h(n-1)*(4*n-2)/(n+1);

//斯特林数
    for(int i=1;i<30;i++)
        S[i][1]=1;
    for(int i=2;i<30;i++)
        for(int j=2;j<30;j++)
            S[i][j]=S[i-1][j-1]+j*S[i-1][j];

//欧拉辗转数
dp[1][1]=1;
for(int i=2;i<23;i++)
    for(int j=1;j<i;j++)
        dp[i][j]=dp[i][j-1]+dp[i-1][i-j];