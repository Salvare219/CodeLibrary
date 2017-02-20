#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


vector<int> gra[100005];
int sg(int now,int fa)
{
    int sum=0;
    for(int i=0;i<gra[now].size();i++)
        if(gra[now][i]!=fa) sum^=sg(gra[now][i],now)+1;
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,y;
        scanf("%d",&n);
        for(int i=n;i>-1;i--)
            gra[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        if(sg(1,0)) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
