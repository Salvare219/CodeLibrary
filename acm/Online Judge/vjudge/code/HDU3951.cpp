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
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        bool flag=0;
        if(k>=n) flag=1;
        else if(k==1) flag=n%2;
        else flag=0;
        if(flag) printf("Case %d: first\n",ti++);
        else printf("Case %d: second\n",ti++);
    }
    return 0;
}
