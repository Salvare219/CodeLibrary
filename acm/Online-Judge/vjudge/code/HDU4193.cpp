#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int num[1000005];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        long long sum=0,m=-0x3fffffff;
        for(int i=n-1;i>-1;i--)
            sum+=num[i],m=max(m,sum);
        int ans=n;
        for(int i=n-1;i>-1;i--)
        {
            sum+=num[i];
            if(sum>m) m=sum;
            if(sum<m) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
