#include<bits/stdc++.h>
using namespace std;


pair<int,int>p[100050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=make_pair(x,y);
    }
    sort(p,p+m);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(i==0)
        {
            ans=max(ans,p[i].second+p[i].first-1);
        }
        else
        {
            int d=p[i].first-p[i-1].first;
            int ly=p[i-1].second-d,hy=p[i-1].second+d;
            if(p[i].second<ly||p[i].second>hy)
            {
                puts("IMPOSSIBLE");
                return 0;
            }
            int res=d-abs(p[i].second-p[i-1].second);
            ans=max(ans,max(p[i].second,p[i-1].second)+(res/2));
        }
    }
    ans=max(ans,p[m-1].second+n-p[m-1].first);
    printf("%d\n",ans);
    return 0;
}

