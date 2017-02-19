#include<bits/stdc++.h>
using namespace std;

vector<int> v[200005];
bool f[200005];
int s;

int dfs(int x,int p)
{
    int y,i,j,c=0;
    if(f[x])
        c++;
    for(i=0,j=v[x].size();i<j;i++)
    {
        if((y=v[x][i])==p)
            continue;
        c+=dfs(y,x);
    }
    if(c>=2)
        s++,c=0;
    return c;
}

int main()
{
    freopen("athletic.in","r",stdin);
    freopen("athletic.out","w",stdout);
    int n,m,x,y,i;
    for(scanf("%d",&n),i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v[x].push_back(y);v[y].push_back(x);
    }
    for(scanf("%d",&m),i=0;i<m;i++)
    {
        scanf("%d",&x);
        f[x]=1;
    }
    dfs(1,0);
    printf("%d\n",s);
    return 0;
}
