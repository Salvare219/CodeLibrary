#include<bits/stdc++.h>
using namespace std;


map<string,int>mp;
char name[105][20];
char s[200][200];
int dp[200][200];
int pre[200][200];
bool ok[105];
int ans[205];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",name[i]);
            string c=name[i];
            mp[c]=i;
        }
        int m;scanf("%d",&m);
        getchar();
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
        {
            gets(s[i]);
            string z;
            memset(ok,0,sizeof(ok));
            int len=strlen(s[i]);
            for(int j=0;j<=len;j++)
            {
                if(s[i][j]==':')
                {
                    if(z=="");
                    else
                    {
                        int h=mp[z];
                        for(int k=1;k<=n;k++)
                            ok[k]=1;
                        ok[h]=0;
                        break;
                    }
                    z.clear();
                }
                else if(s[i][j]!='.'&&s[i][j]!=','&&s[i][j]!=' '&&s[i][j]!='!'&&s[i][j]!=0&&s[i][j]!='?')
                {
                    z+=s[i][j];
                }
                else
                {
                    if(mp.find(z)!=mp.end())
                    {
                        ok[mp[z]]=1;
                    }
                    z.clear();
                }
            }
            int f=0,x=-1,y=-1;
            for(int j=0;j<=n;j++)
                if(dp[i-1][j])
                {
                    f++;
                    swap(x,y);
                    x=j;
                }


            for(int j=1;j<=n;j++)
                if(ok[j]==0)
                {
                    if(f>1)
                    {
                        if(j!=x)
                            pre[i][j]=x;
                        else
                            pre[i][j]=y;
                        dp[i][j]=1;
                    }
                    else if(f==1)
                    {
                        if(j!=x)
                        {
                            pre[i][j]=x;
                            dp[i][j]=1;
                        }
                    }
                }
        }
        int f=0;
        for(int i=0;i<=n;i++)
            if(dp[m][i])
            {
                f=1;
                ans[m]=i;
                int now=m,y=i;
                while(now)
                {
                    ans[now]=y;
                    y=pre[now][y];
                    now--;
                }
            }
        if(f==0)
            puts("Impossible");
        else
        {
            for(int i=1;i<=m;i++)
            {
                int p=0;
                while(s[i][p]!=':')p++;
                printf("%s%s\n",name[ans[i]],s[i]+p);
            }
        }
    }
	return 0;
}

