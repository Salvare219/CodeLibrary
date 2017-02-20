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


map<int,bool> p;
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        int sum=0,temp;
        p.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(p[temp]) continue;
            else p[temp]=1;
            sum^=temp;
        }
        if(sum==0 &&p.size()%2==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


