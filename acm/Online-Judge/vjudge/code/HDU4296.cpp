#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int>p[100050];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x,y;
        for(int i=0;i<n;i++)
            scanf("%d%d",&x,&y),p[i]=make_pair(x+y,x);
        sort(p,p+n);
        long long s=0,ans=0;
        for(int i=0;i<n;i++)
        {
            x=p[i].first;y=p[i].second;
            if(s-x+y>ans)
                ans=s-x+y;s+=y;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
