#include <bits/stdc++.h>
using namespace std;


int s[1<<20];
int d[1<<20];
int w[1<<20];
vector<pair<int,int> >ans;
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",d+i,s+i);
    queue<int>q;
    for(int i=0;i<n;i++)
        if(d[i]==1)
            q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        if(d[x]==0)continue;
        int y=w[x]^s[x];
        d[y]--;
        w[y]^=x;
        ans.push_back(make_pair(x,y));
        if(d[y]==1)q.push(y);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
