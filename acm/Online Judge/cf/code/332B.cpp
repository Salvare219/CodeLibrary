#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int num[500000];
long long pre[500000];
long long dp[500000][2];
int fa[500000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",num+i),pre[i+1]=pre[i]+num[i];
    long long ma=0;
    int fl=0;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=pre[i+k]-pre[i];

        if(i>=k)
        {
            if(dp[i-k][0]>ma) ma=dp[i-k][0],fl=i-k;
            dp[i][1]=ma+pre[i+k]-pre[i];
            fa[i]=fl;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
        if(ans<dp[i][1]) ans=dp[i][1],fl=i;
    printf("%d %d\n",fa[fl]+1,fl+1);
    return 0;
}
/*
char str[999999];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d%s",&n,str);
    int now=0,ans=0;
    int fa=0,fb=0;
    for(int i=0;str[i];i++)
    {
        if(now==0)
        {
            if(fa>=3) ans++,fa++,fb=0;
            else if(fb>=3) ans++,fb++,fa=0;
            else
            {
                if(str[i+1]=='a') fa++,fb=0;
                else fb++,fa=0;
            }
        }
        else
        {
            if(str[i]=='a') fa++,fb=0;
            else fb++,fa=0;
        }
        now=(now+1)%n;
    }
    printf("%d\n",ans);
    return 0;
}*/
