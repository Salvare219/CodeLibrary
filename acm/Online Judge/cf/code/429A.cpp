#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[100050],fip;
int now[100050],aim[100050],ans;
void dfs(int s,int p,int d,int a,int b)
{
    int f=0;
    if(d&1)
    {
        if(aim[s]==now[s])f=a;
        else f=a^1;
    }
    else
    {
        if(aim[s]==now[s])f=b;
        else f=b^1;
    }
    if(f)
    {
        if(d&1)a++;
        else b++;
        fip.push_back(s);
    }
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            dfs(gra[s][i],s,d+1,a%2,b%2);
        }
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,x,y;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",now+i);
    for(int i=1;i<=n;i++)
        scanf("%d",aim+i);
    dfs(1,0,0,0,0);
    printf("%d\n",fip.size());
    for(int i=0;i<fip.size();i++)
        printf("%d\n",fip[i]);
    return 0;
}

