#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,ans;
        scanf("%d%d",&n,&m);
        if(m%2) ans=n%2;
        else
        {
            if(n%(m+1)==m) ans=m;
            else ans=n%(m+1)%2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
