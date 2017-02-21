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


int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0) break;
        if(n<m) swap(n,m);
        int c=n%m,sum=1,ans=-1;
        while(c)
        {
            if(n/m>1)
            {
                ans=sum&1;
                break;
            }
            n=m;m=c;
            c=n%m;
            sum++;
        }
        if(ans==-1) ans=sum&1;
        if(ans) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}