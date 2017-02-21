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
    scanf("%d",&n);
    m=2*n-1;
    int sum=0,mmi=9999999,temp,con=0,ze=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&temp);
        mmi=min(abs(temp),mmi);
        if(temp==0) ze=1;
        if(temp<0) con++;
        sum+=abs(temp);
    }
    if((n&1)==0)
    {
        if(ze==0 && con%2) printf("%d\n",sum-2*mmi);
        else printf("%d\n",sum);
    }
    else
    {
        printf("%d\n",sum);
    }
    return 0;
}
