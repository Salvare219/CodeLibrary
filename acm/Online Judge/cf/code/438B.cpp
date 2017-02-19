#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[100500];
int w[100500];
int com[100500];
long long sz[100500];
int ind[100500];
int inv[100500];
int te[100500];
bool cmp(int a,int b)
{
    return w[a]>w[b];
}
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,x,y;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i),com[i]=ind[i]=i,sz[i]=1;
    long long sum=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    sort(ind+1,ind+n+1,cmp);
    for(int i=1;i<=n;i++)
        inv[ind[i]]=i;
    for(int i=1;i<=n;i++)
    {
        x=ind[i];
        int cnt=0;
        long long tot=0;
        for(int j=0;j<gra[x].size();j++)
            if(inv[y=gra[x][j]]<i)
                te[cnt++]=find(y);
        sort(te,te+cnt);
        cnt=unique(te,te+cnt)-te;
        for(int j=0;j<cnt;j++)
        {
            tot+=sz[te[j]];
            com[te[j]]=x;
        }
        sz[x]=tot+1;
        sum+=2*tot*w[x];
        for(int j=0;j<cnt;j++)
            sum+=(tot-sz[te[j]])*sz[te[j]]*w[x];
    }
    printf("%.6f\n",1.0*sum/n/(n-1));
    return 0;
}
