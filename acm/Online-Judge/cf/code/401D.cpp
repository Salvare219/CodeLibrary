#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long dp[1<<18][100];
int con[10];
int q[1<<18];
bool in[1<<18];
bool v[20];
int tail,front;
int sz;
int ten[20];
int m;
int dfs(int st,int d,int how,int add,int o)
{
    if(d==0)
    {
        int s=0;
        for(int i=0;i<sz;i++)
            if(v[i])s|=(1<<i);
        for(int i=0;i<m;i++)
            dp[s][(i+add)%m]=dp[s][(i+add)%m]+dp[o][i];
        if(in[s]==0)
            q[front++]=s,in[s]=1;
    }
    else
    {
        for(int i=st;i<sz;i++)
            if(v[i]==0)v[i]=1,dfs(i+1,d-1,how,(add+how*ten[i])%m,o),v[i]=0;
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    char n[200];
    scanf("%s%d",n,&m);
    sz=strlen(n);ten[sz-1]=1;
    for(int i=sz-2;i>-1;i--)
        ten[i]=ten[i+1]*10%m;
    for(int i=0;i<sz;i++)
        con[n[i]-'0']++;
    dp[0][0]=1;
    tail=0;front=1;
    q[0]=0;in[0]=1;
    for(int i=0;i<10;i++)
        if(con[i])
        {
            int ed=front;
            while(tail<ed)
            {
                int s=q[tail++];
                for(int j=0;j<sz;j++)
                    if((1<<j)&s)v[j]=1;
                    else v[j]=0;
                if(i==0)dfs(1,con[i],i,0,s);
                else dfs(0,con[i],i,0,s);
            }
        }
    printf("%I64d\n",dp[(1<<sz)-1][0]);
    return 0;
}
