#include<bits/stdc++.h>
using namespace std;


pair<int,int>p[200050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]=make_pair(x+y,x-y);
    }
    sort(p,p+n);
    int ans=0,now=-2000000005;
    for(int i=0;i<n;i++)
        if(now<=p[i].second)
        {
            now=p[i].first;
            ans++;
        }
    printf("%d\n",ans);
    return 0;
}
