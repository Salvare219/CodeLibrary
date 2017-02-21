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


vector<int> bit[100005];
int dept[100005],wic[100005];
vector<int> gra[100005];
int query(int w,int x)
{
    int s=0;
    while(x)
    {
        s+=bit[w][x];
        x-=x&-x;
    }
    return s;
}
void updat(int w,int v,int x)
{
    while(x<bit[w].size())
    {
        bit[w][x]+=v;
        x+=x&-x;
    }
}
void dfs(int s,int de,int FA,int w)
{
    bit[w].push_back(0);
    dept[s]=de;wic[s]=w;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=FA) dfs(gra[s][i],de+1,s,w);
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,q,x,y;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=1;i<=n;i++)
        {
			gra[i].clear();
			bit[i-1].clear();
		}
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        for(int i=0;i<gra[1].size();i++)
        {
            bit[i+1].push_back(0);bit[i+1].push_back(0);
            dfs(gra[1][i],1,1,wic[gra[1][i]]=i+1);
        }
        int ma=0;
        for(int i=1;i<=n;i++) ma=max(ma,dept[i]);
        for(int i=0;i<=ma;i++) bit[0].push_back(0);
        bit[0].push_back(0);
        int v,x,d,t;
		int root=0;
        for(int i=0;i<q;i++)
        {
            scanf("%d",&t);
            if(t)
            {
                scanf("%d",&v);
                if(v!=1) printf("%d\n",query(wic[v],dept[v])+query(0,dept[v]));
				else printf("%d\n",root);
            }
            else
            {
                scanf("%d%d%d",&v,&x,&d);
                if(v==1) 
				{
					updat(0,x,1);
					updat(0,-x,min(d,(int)bit[0].size()-1)+1);
					root+=x;
				}
                else
                {
                    if(dept[v]>d)
                    {
                        updat(wic[v],-x,min(dept[v]+d,(int)bit[wic[v]].size()-1)+1);
                        updat(wic[v],x,dept[v]-d);
                    }
					else if(dept[v]==d) 
					{
                        updat(wic[v],-x,min(dept[v]+d,(int)bit[wic[v]].size()-1)+1);
                        updat(wic[v],x,dept[v]-d+1);
						root+=x;
					}
                    else
                    {
						root+=x;
                        updat(wic[v],-x,min(dept[v]+d,(int)bit[wic[v]].size()-1)+1);
                        updat(wic[v],x,1);
						updat(wic[v],-x,1);
						updat(wic[v],x,min(d-dept[v],(int)bit[wic[v]].size()-1)+1);
						updat(0,x,1);
                        updat(0,-x,min(d-dept[v],(int)bit[0].size()-1)+1);
                    }
                }
            }
        }
    }
    return 0;
}
