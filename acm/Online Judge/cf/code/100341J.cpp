#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


long long g[305][305];
long long h[305][305];
int main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j)g[i][j]=h[i][j]=0;
            else
            {
                g[i][j]=1ll<<50;
                h[i][j]=1;
            }
        }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x--;y--;
        g[x][y]=g[y][x]=min(g[x][y],(long long)w);
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                long long f=g[i][k]+g[k][j];
                if(f==g[i][j])
                    h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
                else if(f<g[i][j])
                {
                    h[i][j]=h[i][k]+h[k][j];
                    g[i][j]=f;
                }
            }
    long long ans=0,cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ans+=h[i][j],cnt++;
    printf("%.8f\n",1.0*ans/cnt);
    return 0;
}
