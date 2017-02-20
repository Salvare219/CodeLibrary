#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int sg[]={0,1,0,0,1,1};
int main()
{
 //   freopen("1.txt","r",stdin);
    int t,ts=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0,temp;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(sg[i%6]) sum^=temp;
        }
        if(sum) printf("Case %d: Alice\n",ts++);
        else printf("Case %d: Bob\n",ts++);
    }
    return 0;
}

