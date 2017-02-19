#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int w[600];
vector<int>gra[600];
int v[600];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y,z,ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",w+i);
            ans=max(ans,w[i]);
            gra[i].clear();
            v[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            x=i;
            for(int j=0;j<gra[i].size();j++)
                v[gra[i][j]]++;
            for(int j=0;j<gra[i].size();j++)
            {
                y=gra[i][j];
                ans=max(ans,w[x]+w[y]);
                for(int k=0;k<gra[y].size();k++)
                    v[gra[y][k]]++;
                for(int k=0;k<gra[y].size();k++)
                    if(v[gra[y][k]]==2)
                    {
                        z=gra[y][k];
                        ans=max(ans,w[x]+w[y]+w[z]);
                        for(int l=0;l<gra[z].size();l++)
                            v[gra[z][l]]++;
                        for(int l=0;l<gra[z].size();l++)
                            if(v[gra[z][l]]==3)
                                ans=max(ans,w[x]+w[y]+w[z]+w[gra[z][l]]);
                        for(int l=0;l<gra[z].size();l++)
                            v[gra[z][l]]--;
                    }
                for(int k=0;k<gra[y].size();k++)
                    v[gra[y][k]]--;
            }
            for(int j=0;j<gra[i].size();j++)
                v[gra[i][j]]--;
        }
        printf("%d\n",ans);
    }
	return 0;
}
