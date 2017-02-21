#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;




int sg[205];
int dfs(int x)
{
    if(sg[x]!=-1) return sg[x];
    bool g[4010]={0};
    for(int i=x-2;i>=0;i--)
    {
        int t=dfs(i)^dfs(x-i-2);
        g[t]=1;
    }
    for(int i=0;;i++)
    if(g[i]==0) return sg[x]=i;
}
int main()
{
    memset(sg,-1,sizeof(sg));
	sg[0]=sg[1]=0;
    int x,y;
    while(scanf("%d%d",&x,&y)==2)
    {
		if(x%2==0 && x!=2) printf("WIN\n");
		else if(y%2==0 && y!=2) printf("WIN\n");
		else 
		{
			x-=2;y-=2;
			if(dfs(x)+dfs(y)==0) printf("LOSE\n");
			else printf("WIN\n");
		}
    }
	return 0;
}
