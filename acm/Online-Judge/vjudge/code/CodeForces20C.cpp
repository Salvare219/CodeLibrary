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


/*
int main()
{
    freopen("1.txt","w",stdout);
    printf("100000 99999\n");
    for(int i=0;i<99999;i++)
    {
        printf("%d %d",i+1,i+2);
        int a=rand()*100;
        while(a<100000) a=rand()*100;
        printf(" %d\n",a);
    }
    return 0;
}*/



vector<pair<int,int> > lin[100005];
pair<int,long long> poi[1800005];
long long vis[100005];
int p[100005],n,m;
bool cmp(pair<int,long long> a,pair<int,long long> b)
{
	return a.second>b.second;
}
int Dijkstra(int sta,int end)
{
	if(sta==end) return 0;
    int mx,k=1,to;
    long long w,mdis;
    for(int i=1;i<=n;i++)
    {
        vis[i]=0x3fffffff;
        vis[i]*=vis[i];
    }
	poi[0].first=sta;
	poi[0].second=0;
	vis[sta]=0;
    while(k)
    {
        mdis=poi[0].second;
        mx=poi[0].first;
        if(mx==end) return mdis;
        pop_heap(poi,poi+k,cmp);
        k--;
        for(int i=0;i<lin[mx].size();i++)
        {
			to=lin[mx][i].first;
			w=lin[mx][i].second;
            if(w+mdis<vis[to])
            {
                if(to==97675)
                    int kk=0;
                vis[to]=w+mdis;
                p[to]=mx;
                poi[k].second=vis[to];
                poi[k++].first=to;
                push_heap(poi,poi+k,cmp);
            }
        }
    }
    return -1;
}
int main()
{
    int x,y,w;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        lin[x].push_back(make_pair(y,w));
        lin[y].push_back(make_pair(x,w));
    }
    if(Dijkstra(1,n)==-1) printf("-1\n");
    else
    {
        int s=n,k=0;
        for(;s!=1;s=p[s]) vis[k++]=s;
        printf("%d",1);
        for(int i=k-1;i>-1;i--)
            printf(" %d",vis[i]);
    }
    return 0;
}
