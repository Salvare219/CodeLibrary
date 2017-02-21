#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
  //  freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<=y-2)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
