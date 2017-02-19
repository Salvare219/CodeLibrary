#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    int x,y,z;
    bool operator<(const p&a)const
    {
        return z<a.z;
    }
}a[2005*2005];
vector<int>gra[2005];
int d[2005][2005];
int ta[2005],ca;
int tb[2005],cb;
bool v[2005];
int com[2005];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
void dfs1(int s)
{
    ta[ca++]=s;v[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(v[gra[s][i]]==0)
            dfs1(gra[s][i]);
    v[s]=0;
}
void dfs2(int s)
{
    tb[cb++]=s;v[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(v[gra[s][i]]==0)
            dfs2(gra[s][i]);
    v[s]=0;
}
int ax[2005];
int ay[2005];
int az[2005];
int main()
{
    int n;
    bool sb=0;
    while(~scanf("%d",&n))
    {
        if(sb)putchar(10);sb=1;
        int x,y,z,k=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i!=j)d[i][j]=0x3fffffff;
                else d[i][j]=0;
                scanf("%d",&x);
                if(j>i)
                {
                    a[k].x=i;
                    a[k].y=j;
                    a[k++].z=x;
                }
            }
        sort(a,a+k);
        for(int i=1;i<=n;i++)
            com[i]=i,gra[i].clear();
        bool sk=0;
        int f=0;
        for(int i=0;i<k;i++)
        {
            x=a[i].x;
            y=a[i].y;
            z=a[i].z;
            if(find(x)==find(y))
            {
                if(d[x][y]==z);
                else
                {
                    d[x][y]=d[y][x]=z;
                    ca=0;
                    dfs1(x);
                    for(int i=0;i<ca;i++)
                        for(int j=i+1;j<ca;j++)
                        {
                            int l1=d[ta[i]][x]+z+d[ta[j]][y];
                            int l2=d[ta[i]][y]+z+d[ta[j]][x];
                            int ll=min(l1,l2);
                            ll=min(ll,d[ta[i]][ta[j]]);
                            d[ta[i]][ta[j]]=d[ta[j]][ta[i]]=ll;
                        }
                    ax[f]=x;
                    ay[f]=y;
                    az[f++]=z;
                    sk=1;
                }
            }
            else
            {
                ca=cb=0;
                dfs1(x);
                dfs2(y);
                gra[x].push_back(y);
                gra[y].push_back(x);
                for(int i=0;i<ca;i++)
                    for(int j=0;j<cb;j++)
                    {
                        int ll=d[ta[i]][x]+z+d[tb[j]][y];
                        d[ta[i]][tb[j]]=d[tb[j]][ta[i]]=ll;
                    }
                ax[f]=x;
                ay[f]=y;
                az[f++]=z;
                com[find(x)]=find(y);
            }
        }
        if(sk==0)
        {
            ax[f]=ax[0];
            ay[f]=ay[0];
            az[f++]=az[0];
        }
        for(int i=0;i<f;i++)
            printf("%d %d %d\n",ax[i],ay[i],az[i]);
    }
	return 0;
}
