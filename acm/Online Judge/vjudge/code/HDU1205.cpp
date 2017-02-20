#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,mx=0;scanf("%d",&n);
        long long sum=0;
        for(int i=0;i<n;i++)
            scanf("%d",&x),sum+=x,mx=max(mx,x);
        mx--;sum--;
        puts(sum<2*mx?"No":"Yes");
    }
    return 0;
}
