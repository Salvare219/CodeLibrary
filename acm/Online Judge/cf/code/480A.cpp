#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;



pair<int,int>pa[6000];
int main()
{
    int n;scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        pa[i]=make_pair(x,y);
    }
    int ans=0;
    sort(pa,pa+n);
    for(int i=0;i<n;i++)
    {
        if(pa[i].second>=ans)ans=pa[i].second;
        else ans=pa[i].first;
    }
    printf("%d\n",ans);
    return 0;
}
