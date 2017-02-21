#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>gra[300050];
bool ans[300050];
bool sb(int s)
{
    int sum=0;
    for(int i=0;i<gra[s].size();i++)
        sum+=1-(ans[s]^ans[gra[s][i]]);
    return sum>1;
}
void dfs(int s)
{
    ans[s]^=1;
    for(int i=0;i<gra[s].size();i++)
        if(sb(gra[s][i]))dfs(gra[s][i]);
}
int main()
{
    int n,m,x,y;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&x,&y),gra[x].push_back(y),gra[y].push_back(x);
    for(int i=1;i<=n;i++)
        if(sb(i))dfs(i);
    for(int i=1;i<=n;i++)
        putchar('0'+ans[i]);putchar(10);
    return 0;
}
