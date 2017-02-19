#include <bits/stdc++.h>
using namespace std;

struct ps
{
    int x,y,l;
    int mx;
    double p;
    bool operator==(const ps&a)const
    {
        return x==a.x&&y==a.y;
    }
}cov[100050];
int a[100050];
int nex[100050];
int lag;
vector<int>gra[100050];
bool ok(int i,int j)
{
    if(cov[i].x>=cov[j].x&&cov[i].y<=cov[j].y)return 1;
    else return 0;
}
double dp[5050][10050];
double dt[10050];
double s1[10050],s2[10050];
void dfs(int s,int p)
{
    int y,fa=0;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
            dfs(y=gra[s][i],s);
    for(int i=cov[s].x;i<=cov[s].y;i=nex[i])
        fa=max(fa,a[i]);
    nex[cov[s].x-1]=cov[s].y+1;
    if(fa<lag-5001)dp[s][0]=1.0;
    else dp[s][fa-lag+5001]=1.0;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            y=gra[s][i];
            s1[0]=dp[s][0];
            s2[0]=dp[y][0];
            for(int j=1;j<=10005;j++)
            {
                s1[j]=s1[j-1]+dp[s][j];
                s2[j]=s2[j-1]+dp[y][j];
            }
            for(int j=0;j<=10005;j++)
            {
                dt[j]=dp[s][j]*s2[j]+s1[j]*dp[y][j]-dp[s][j]*dp[y][j];
            }
            for(int j=0;j<=10005;j++)
                dp[s][j]=dt[j];
        }
    double e=cov[s].p;
    for(int i=0;i<=10005;i++)
    {
        dt[i]=dp[s][i]*(1-e);
        if(i-1>=0)dt[i]+=dp[s][i-1]*e;
    }
    for(int i=0;i<=10005;i++)
        dp[s][i]=dt[i];
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,q;scanf("%d%d",&n,&q);q++;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),lag=max(lag,a[i]);
    for(int i=1;i<q;i++)
        scanf("%d%d%lf",&cov[i].x,&cov[i].y,&cov[i].p),cov[i].l=cov[i].y-cov[i].x+1;
    cov[0].x=1;cov[0].y=n;
    cov[0].p=0.0;cov[0].l=n;
    for(int i=1;i<q;i++)
    {
        int l=1000000,f=-1;
        for(int j=i-1;j>-1;j--)
            if(cov[j]==cov[i])
            {
                f=j;
                break;
            }
        if(f==-1)
        {
            for(int j=0;j<q;j++)
                if(cov[i]==cov[j]);
                else
                {
                    if(ok(i,j))
                    {
                        if(cov[j].l<=l)
                            l=cov[j].l,f=j;
                    }
                }
        }
        gra[i].push_back(f);
        gra[f].push_back(i);
        //printf("%d %d\n",f,i);
    }
    for(int i=1;i<=n;i++)
        nex[i]=i+1;
    dfs(0,-1);
    double ans=0.0;
    for(int i=1;i<=10005;i++)
        ans+=dp[0][i]*(lag+i-5001);
    printf("%.10f\n",ans);
    return 0;
}
