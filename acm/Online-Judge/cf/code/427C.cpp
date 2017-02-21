#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<int> gra[100005];
bool vis[100005];
int stack[100005],sk;
int low[100005],scc[100005];
int timer,cnt;
void tarjan(int s)
{
    vis[s]=1;
    int to,temp=low[s]=++timer;
    stack[sk++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(vis[to]==0) tarjan(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--sk];
            low[to]=0x3fffffff;
            scc[to]=cnt;
        }while(stack[sk]!=s);
        cnt++;
    }
}
int w[100005];
int ans[100005],how[100005];
const int mod=1000000007;
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    cnt=1;timer=0;
    for(int i=1;i<=n;i++)
        scanf("%d",w+i),ans[i]=0x3fffffff;
    scanf("%d",&m);
    int x,y;
    for(int i=0;i<m;i++)
        scanf("%d%d",&x,&y),gra[x].push_back(y);
    for(int i=1;i<=n;i++)
        if(vis[i]==0)tarjan(i);
    for(int i=1;i<=n;i++)
    {
        x=scc[i];
        if(ans[x]==w[i])how[x]++;
        else if(ans[x]>w[i])ans[x]=w[i],how[x]=1;
    }
    long long fin=0;
    long long fin2=1;
    for(int i=1;i<cnt;i++)
        fin+=ans[i],fin2=fin2*how[i]%mod;
    printf("%I64d %I64d\n",fin,fin2);
    return 0;
}
