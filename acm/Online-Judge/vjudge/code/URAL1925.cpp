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
//	freopen("1.txt","r",stdin);
	int n,k,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		sum+=x-y-2;
	}
	sum+=k-2;
	if(sum<0) printf("Big Bang!\n");
	else printf("%d\n",sum);
    return 0;
}
 				    