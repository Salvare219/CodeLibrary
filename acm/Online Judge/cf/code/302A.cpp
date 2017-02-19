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
	int n,m,a=0,b=0,temp;
    scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
        scanf("%d",&temp);
        if(temp==1) a++;
        else b++;
	}
	a=min(a,b);
	int l,r;
	for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        if((r-l+1)&1) printf("0\n");
        else
        {
            if((r-l+1)/2<=a) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
