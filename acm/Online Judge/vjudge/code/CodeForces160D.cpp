#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int x,y,w,i,ty;
    bool operator<(p a)const{return w<a.w;}
}e[100050];
int com[100050];
bool vis[100050];
int low[100050],cnt;
vector<pair<int,int> >gra[100050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
char lib[4][22]={"none","at least one","any"};
int dfs(int s,int p)
{
    int to,temp=low[s]=cnt++;vis[s]=1;
    bool f=1;
    for(int i=0;i<gra[s].size();i++)
    {
        to=find(gra[s][i].first);
        if(to==s)continue;
        if(f&&to==p){f=0;continue;}
        if(vis[to])low[s]=min(low[s],low[to]);
        else
        {
            dfs(to,s);low[s]=min(low[s],low[to]);
            if(low[to]>temp)e[gra[s][i].second].ty=2;
        }
    }
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)com[i]=i;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w),e[i].i=i;
    sort(e,e+m);
    int j=0,k,z,x,y;
    while(j<m)
    {
        k=z=j;
        while(k<m&&e[j].w==e[k].w)
        {
            x=find(e[k].x);y=find(e[k].y);
            if(x==y)e[k].ty=0;
            else e[k].ty=1,gra[x].push_back(make_pair(y,k)),gra[y].push_back(make_pair(x,k));
            k++;vis[x]=0;vis[y]=0;
        }
        while(z<k)
        {
            x=find(e[z].x);y=find(e[z].y);cnt=0;
            if(x!=y&&vis[x]==0)dfs(x,0);z++;
        }
        while(j<k)
        {
            int x=find(e[j].x),y=find(e[j].y);
            if(x!=y)com[x]=y;j++;
        }
    }
    for(int i=0;i<m;i++)
        com[e[i].i]=e[i].ty;
    for(int i=0;i<m;i++)
        puts(lib[com[i]]);
	return 0;
}
