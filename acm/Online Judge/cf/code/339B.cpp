#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int now=1,temp;
    long long sum=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&temp);
        if(temp>=now)
        {
            sum+=temp-now;
            now=temp;
        }
        else
        {
            sum+=n+temp-now;
            now=temp;
        }
    }
    printf("%I64d\n",sum);
	return 0;
}
