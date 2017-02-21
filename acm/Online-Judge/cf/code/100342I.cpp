#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


int n,m;
vector<int>ss[20050];
vector<int>gra[20005];
bool v[20005],cut[20005];
int low[20005],dfn[20005];
int timer,root;
int dfs(int s,int p)
{
    bool f=1;
    int y,cnt=0,sum=0,sum2=0;
    v[s]=1;
    dfn[s]=low[s]=timer++;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])==p&&f)f=0;
        else
        {
            if(v[y])low[s]=min(low[s],dfn[y]);
            else
            {
                int fa=dfs(y,s);
                sum2+=fa;
                cnt++;
                low[s]=min(low[s],low[y]);
                if((s!=root&&low[y]>=dfn[s])||(s==root&&cnt>1))
                {
                    cut[s]=1;
                    sum+=fa;
                    ss[s].push_back(fa);
                }
            }
        }
    ss[s].push_back(n-1-sum);
    return sum2+1;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    timer=0;
    for(int i=1;i<=n;i++)
        if(v[i]==0)
        {
            root=i;
            dfs(i,0);
        }

    //for(int i=0;i<ss[2].size();i++)
    //    printf("%d ",ss[2][i]);

    for(int i=1;i<=n;i++)
        if(cut[i])
        {
            long long sum=0,ans=0;
            for(int j=0;j<ss[i].size();j++)
                sum+=ss[i][j];
            for(int j=0;j<ss[i].size();j++)
                ans+=(sum-ss[i][j])*ss[i][j];
            ans/=2;
            printf("%I64d\n",ans+n-1);
        }
        else
            printf("%d\n",n-1);
    return 0;
}
