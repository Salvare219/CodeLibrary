#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>ans;
vector<pair<int,int> >gra[100050];
int dfs(int s,int p,int yao)
{
    int f=0;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i].first!=p)
            f=max(f,dfs(gra[s][i].first,s,gra[s][i].second));
    if(yao==2&&f==0)ans.push_back(s),f=1;
    return f;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,x,y,z;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        gra[x].push_back(make_pair(y,z));
        gra[y].push_back(make_pair(x,z));
    }
    dfs(1,0,1);
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);putchar(10);
    return 0;
}
