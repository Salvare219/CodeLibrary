#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char sm[1005];
double now[700];
bool inq[700];
bool col[700];
double cur,ans;
int sum[700],cnt[700],h;
int bh[700];
vector<pair<int,int> >gra[700];
bool spfa_dfs(int s)
{
    int to,w;
    col[s]=inq[s]=1;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i].first;
        w=gra[s][i].second;
        if(now[to]+1e-4<now[s]+w-ans)
        {
            now[to]=now[s]+w-ans;
            if(inq[to])
            {
                cur=1.0*(sum[s]-sum[to]+w)/(cnt[s]-cnt[to]+1);
                return 1;
            }
            sum[to]=sum[s]+w;cnt[to]=cnt[s]+1;
            if(spfa_dfs(to))return 1;
        }
    }
    inq[s]=0;
    return 0;
}
double ok()
{
    for(int i=0;i<h;i++)col[i]=inq[i]=0;
    for(int i=0;i<h;i++)
        if(col[i]==0)
        {
            sum[i]=cnt[i]=0;
            if(spfa_dfs(i))return cur;
        }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int x,y,w;
        for(int i=0;i<h;i++)gra[i].clear();
        memset(bh,-1,sizeof(bh));
        h=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",sm);
            w=strlen(sm);
            x=(sm[0]-'a')*26+sm[1]-'a';
            y=(sm[w-2]-'a')*26+sm[w-1]-'a';
            if(bh[x]==-1)bh[x]=h++;
            if(bh[y]==-1)bh[y]=h++;
            gra[bh[x]].push_back(make_pair(bh[y],w));
        }
        double din=-1.0;ans=0.0;
        while(ans-din>1e-4)
            din=ans,ans=ok();
        if(ans>0.5)printf("%.2f\n",ans);
        else puts("No solution.");
    }
    return 0;
}
