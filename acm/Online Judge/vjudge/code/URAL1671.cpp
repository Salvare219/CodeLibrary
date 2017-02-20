#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int com[100050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
bool v[100050];
int f[100050];
int x[100050],y[100050];
int ans[100050];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)com[i]=i;
    for(int i=0;i<m;i++)
        scanf("%d%d",x+i,y+i);
    int q;scanf("%d",&q);
    for(int i=0;i<q;i++)
        scanf("%d",f+i),v[--f[i]]=1;
    int sz=n;
    for(int i=0;i<m;i++)
        if(v[i]==0)
        {
            int a=find(x[i]),b=find(y[i]);
            if(a!=b)
            {
                sz--;
                com[a]=b;
            }
        }
    for(int i=q-1;i>=0;i--)
    {
        ans[i]=sz;
        int a=find(x[f[i]]),b=find(y[f[i]]);
        if(a!=b)
        {
            sz--;
            com[a]=b;
        }
    }
    for(int i=0;i<q;i++)
        printf("%d%c",ans[i],i==q-1?10:' ');
	return 0;
}
