#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#include<map>
map<int,pair<long long,int> >mp;
struct p
{
    int x;
    long long y;
    int i;
}hi[100005];
vector<int>gra[100005],q[100005],id[100005];
bool vis[100005];
int com[100005];
int ans[100005];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
void dfs(int s,int p)
{
    int x;
    for(int i=0;i<gra[s].size();i++)
        if((x=gra[s][i])!=p)dfs(x,s),com[x]=s;
    vis[s]=1;
    for(int i=0;i<q[s].size();i++)
        if(vis[x=q[s][i]]) ans[id[s][i]]=find(x);
}
int st[100005];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    long long x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%I64d",&hi[i].x,&hi[i].y);
        hi[i].i=i;
    }
    int k=1;st[0]=n-1;
    for(int i=n-2;i>-1;i--)
    {
        if(k==1)
        {
            st[k++]=i;
            gra[st[0]].push_back(i);
        }
        else
        {
            while(k>1)
            {
                long long x1,y2,x2,y1;
                int a=st[k-2],b=st[k-1];
                x1=hi[b].x-hi[i].x;
                x2=hi[a].x-hi[i].x;
                y1=hi[b].y-hi[i].y;
                y2=hi[a].y-hi[i].y;
                if(y2*x1>y1*x2) k--;
                else break;
            }
            gra[st[k-1]].push_back(i);
            st[k++]=i;
        }
    }
    int qq,a,b;scanf("%d",&qq);
    for(int i=0;i<n;i++)com[i]=i;
    for(int i=0;i<qq;i++)
    {
        scanf("%d%d",&a,&b);a--;b--;
        q[a].push_back(b);
        q[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
    }
    dfs(n-1,n-1);
    for(int i=0;i<qq;i++)
        printf("%d\n",ans[i]+1);
    return 0;
}
