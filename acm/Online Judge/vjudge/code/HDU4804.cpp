#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;



const int mod=1000000007;
int maz[500];
char s[500];
vector<int>sta[1050];
int n,m,c,d;;
void dfs(int s,int now,int h,int fa)
{
    if(s==(1<<m)-1)
    {
        sta[fa].push_back(now*100+h);
        //printf("%d %d %d\n",fa,now,h);
    }
    else
    {
        for(int i=0;i<m;i++)
            if(((1<<i)&s)==0)
            {
                if(h+1<=d)
                    dfs(s|(1<<i),now,h+1,fa);
                if(i+1<m&&((1<<(i+1))&s)==0)
                    dfs(s|(1<<i)|(1<<(i+1)),now,h,fa);
                dfs(s|(1<<i),now|(1<<i),h,fa);
                break;
            }
    }
}
int dp[105][1050][25];
int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&c,&d))
    {
        int lim=1<<m;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            maz[i]=0;
            for(int j=0;j<m;j++)
                if(s[j]=='0')maz[i]|=1<<j;
        }
        for(int i=0;i<lim;i++)
            sta[i].clear();
        for(int i=0;i<lim;i++)
            dfs(i,0,0,i);
        for(int i=0;i<=n;i++)
            for(int j=0;j<lim;j++)
                for(int k=0;k<=d;k++)
                    dp[i][j][k]=0;
        dp[0][maz[0]][0]=1;
        maz[n]=0;
        for(int i=1;i<=n;i++)
        {
            int s=maz[i];
            for(int j=0;j<lim;j++)
                for(int k=0;k<=d;k++)
                    if(dp[i-1][j][k])
                    {
                        int f=sta[j].size(),x,y;
                        for(int z=0;z<f;z++)
                        {
                            x=sta[j][z]/100;
                            y=sta[j][z]%100;
                            if((x&maz[i])==0&&k+y<=d)
                            {
                                int h=x|maz[i];
                                dp[i][h][k+y]=dp[i][h][k+y]+dp[i-1][j][k];
                                if(dp[i][h][k+y]>=mod)dp[i][h][k+y]-=mod;
                            }
                        }
                    }
        }
        long long ans=0;
        for(int i=c;i<=d;i++)
            ans=(ans+dp[n][0][i])%mod;
        printf("%d\n",(int)ans);
    }
    return 0;
}
