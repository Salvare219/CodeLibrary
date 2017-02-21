#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int a[1005],b[1005],ans[1005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",b+i);
		}
		long long ne=0;
		for(int i=n-1;i>-1;i--)
		{
			if(b[i]>a[i]+ne) 
			{
				ans[i]=a[i]+ne;
				ne=0;
			}
			else 
			{
				ans[i]=b[i];
				ne-=b[i]-a[i];
			}
		}
		if(ne) printf("Myon\n");
		else 
		{
			for(int i=0;i<n;i++)
				if(i) printf(" %d",ans[i]);
				else printf("%d",ans[i]);
			putchar(10);
		}
	}
    return 0;
}