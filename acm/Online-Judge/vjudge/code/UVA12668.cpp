#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char maz[200][200];
int x,y;
int a[200][200],b[200][200];
vector<int> gra[10050];
bool vis[10050];
int p[10050];
bool find(int s)
{
	for(int i=0;i<gra[s].size();i++)
		if(vis[gra[s][i]]==0)
		{
			vis[gra[s][i]]=1;
			if(p[gra[s][i]]==0 || find(p[gra[s][i]]))
			{
				p[gra[s][i]]=s;
				return 1;
			}
		}
	return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%s",maz[i]);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        x=1;y=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool f=0;
                while(j<n&&maz[i][j]=='X')j++;
                while(j<n&&maz[i][j]=='.')a[i][j++]=x,f=1;
                if(f)x++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool f=0;
                while(j<n&&maz[j][i]=='X')j++;
                while(j<n&&maz[j][i]=='.')b[j++][i]=y,f=1;
                if(f)y++;
            }
        }
        for(int i=1;i<x;i++)gra[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(maz[i][j]=='.')
                    gra[a[i][j]].push_back(b[i][j]);
        int ans=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<x;i++)
        {
            memset(vis,0,sizeof(vis));
            ans+=find(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
