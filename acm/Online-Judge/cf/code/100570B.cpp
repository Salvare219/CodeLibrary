#include<bits/stdc++.h>
using namespace std;


vector<int>to[100050],col[100050],we[100050];
int dp1[100050];
long long dp2[100050],dp3[100050];
int n,m,c;
bool inq[100050];
void spfa(int s)
{
    queue<int>q;
    q.push(s);
    for(int i=1;i<=n;i++)
        dp1[i]=-1,dp2[i]=dp3[i]=1ll<<60;
    dp2[s]=dp3[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        inq[x]=0;
        for(int i=0;i<to[x].size();i++)
        {
            int y=to[x][i],co=col[x][i],wi=we[x][i],h=0;
            long long ss;
            if(co==dp1[x])ss=dp3[x];
            else ss=dp2[x];
            if(dp1[y]==co)
            {
                if(dp2[y]>ss+wi)
                {
                    dp2[y]=ss+wi;
                    h=1;
                }
            }
            else
            {
                if(dp2[y]>ss+wi)
                {
                    dp3[y]=dp2[y];
                    dp2[y]=ss+wi;
                    dp1[y]=co;
                    h=1;
                }
                else if(dp3[y]>ss+wi)
                {
                    dp3[y]=ss+wi;
                    h=1;
                }
            }
            if(h)
            {
                if(inq[y]==0)
                {
                    inq[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&c);
    for(int i=0;i<m;i++)
    {
        int x,y,w,z;
        scanf("%d%d%d%d",&x,&y,&w,&z);
        to[x].push_back(y);
        we[x].push_back(w);
        col[x].push_back(z);
    }
    int s,q;
    scanf("%d%d",&s,&q);
    spfa(s);
    while(q--)
    {
        scanf("%d",&s);
        long long ans=dp2[s];
        if(ans<(1ll<<60));
        else ans=-1;
        printf("%I64d\n",ans);
    }
    return 0;
}
