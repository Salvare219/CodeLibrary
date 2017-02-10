int num[100050];
int dp[100050][30];
int to[100050];
void rmq()
{
    for(int i=0;i<n;i++)dp[i][0]=num[i];
    for(int l=2,s=0;l<=n;l<<=1,s++)
        for(int i=0;i+l<=n;i++)
	    dp[i][s+1]=max(dp[i][s],dp[i+l/2][s]);
}
void pre_log()
{
    to[1]=0;
    for(int i=2;i<n;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
const double C=log(2.0);
int query(int l,int r)  //求 l 到 r 最值(从 0 标号) 
{
    if(l>r) swap(l,r);
    int mid=log(r-l+1.0)/C; 
	//mid=to[r-l+1];
    int len=1<<mid;
    return min(dp[l][mid],dp[r-len+1][mid]);
}

二维rmq

int num[305][305];
int dp[305][305][9][9];
void rmq_2d(int n,int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j][0][0]=num[i][j];
    for(int l1=1,x=0;l1<=n;l1<<=1,x++)
        for(int l2=1,y=0;l2<=m;l2<<=1,y++)
            for(int i=0;(x||y)&&i+l1<=n;i++)
                for(int j=0;j+l2<=m;j++)
                {
                    if(y==0)dp[i][j][x][y]=min(dp[i][j][x-1][y],dp[i+l1/2][j][x-1][y]);
                    else dp[i][j][x][y]=min(dp[i][j][x][y-1],dp[i][j+l2/2][x][y-1]);
                }
}
const double C=log(2.0);
int query_2d(int x,int y,int x1,int y1)
{
    if(x>x1)swap(x,x1);
    if(y>y1)swap(y,y1);
    int m1=log(x1-x+1.0)/C,m2=log(y1-y+1.0)/C;
	//m=to[x1-x+1];
    int l1=1<<m1,l2=1<<m2;
    return min(min(dp[x][y][m1][m2],dp[x1-l1+1][y1-l2+1][m1][m2]),
               min(dp[x1-l1+1][y][m1][m2],dp[x][y1-l2+1][m1][m2]));
}