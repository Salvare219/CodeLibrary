#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
 //   freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int sum=0,x,ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x<0)
        {
            if(sum>0)sum--;
            else ans++;
        }
        else sum+=x;
    }
    printf("%d\n",ans);
    return 0;
}
