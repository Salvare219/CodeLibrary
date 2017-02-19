#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;


vector<int> gra[2005];
bool vis[2005];
int stack[2005],k;
int low[2005],dfn[2005],scc[2005];
int timer,cnt;
void tarjan_scc(int s)
{
	vis[s]=1;
	low[s]=dfn[s]=++timer;
	stack[k++]=s;
	int to;
	for(int i=0;i<gra[s].size();i++)
	{
		to=gra[s][i];
		if(dfn[to]==0) 
        {
            tarjan_scc(to);
            low[s]=min(low[to],low[s]);
        }
        else if(vis[to]) low[s]=min(dfn[to],low[s]);
	}
	if(dfn[s]==low[s])
	{
		do
		{
			to=stack[--k];
			vis[to]=0;
			scc[to]=cnt;
		}while(stack[k]!=s);
		cnt++;
	}
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,a,b,c;
	char str[5];
	scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%s",&a,&b,&c,str);
        a++;b++;
        if(str[0]=='A')
        {
            if(c) gra[a+n].push_back(a),gra[b+n].push_back(b);
            else gra[a].push_back(b+n),gra[b].push_back(a+n);
        }
        else if(str[0]=='X')
        {
            if(c) gra[a].push_back(b+n),gra[b].push_back(a+n),gra[a+n].push_back(b),gra[b+n].push_back(a);
            else gra[a+n].push_back(b+n),gra[b+n].push_back(a+n),gra[a].push_back(b),gra[b].push_back(a);
        }
        else
        {
            if(c) gra[a+n].push_back(b),gra[b+n].push_back(a);
            else gra[a].push_back(a+n),gra[b].push_back(b+n);
        }
    }
    cnt=1;timer=0;
    for(int i=0;i<n;i++)
        if(scc[i]==0 && scc[i+n]==0) tarjan_scc(i);
    bool flag=1;
    for(int i=0;i<n;i++)
        if(scc[i]==scc[i+n])
        {
            flag=0;
            break;
        }
    if(flag) printf("YES\n");
    else printf("NO\n");
	return 0;
}
