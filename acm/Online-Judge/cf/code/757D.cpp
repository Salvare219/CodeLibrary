#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
char s[100];
int dp[76][1<<20];
bool v[30][1<<20];
queue<int>q[30];
int main()
{
    //freopen("2.txt","w",stdout);
    int n;scanf("%d%s",&n,s+1);
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
        if(i<30)
        {
            q[i].push(0);
            v[i][0]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i<30)
        {
            while(!q[i].empty())
            {
                int x=q[i].front(),y=i,z;
                q[i].pop();
                int f=0;
                for(int j=y+1;j<=n;j++)
                {
                    f=f*2+s[j]-'0';
                    if(f>20)
                        break;
                    if(f)
                    {
                        z=x|(1<<(f-1));
                        dp[j][z]+=dp[y][x];
                        if(dp[j][z]>=mod)
                            dp[j][z]-=mod;
                        if(v[j][z]==0&&j<30)
                        {
                            v[j][z]=1;
                            q[j].push(z);
                        }
                    }
                }
            }
        }
        else
        {
            for(int j=0;j<(1<<20);j++)
                if(dp[i][j])
                {
                    int f=0;
                    for(int k=i+1;k<=n;k++)
                    {
                        f=f*2+s[k]-'0';
                        if(f>20)
                            break;
                        if(f)
                        {
                            int z=j|(1<<(f-1));
                            dp[k][z]+=dp[i][j];
                            if(dp[k][z]>=mod)
                                dp[k][z]-=mod;
                        }
                    }
                }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        int s=1;
        for(int j=1;j<=20;j++)
        {
            ans+=dp[i][s];
            if(ans>=mod)ans-=mod;
            s=s*2+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
