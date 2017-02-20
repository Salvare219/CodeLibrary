#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[200005];
int main()
{
//    freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",num+i);
			sum^=num[i];
		}
		if(sum)
		{
			printf("Yes\n");
			int c;
			for(int i=0;i<n;i++)
			{
				c=sum;
				c^=num[i];
				if(c<=num[i]) printf("%d %d\n",num[i],c);
			}
		}
		else printf("No\n");
	}
    return 0;
}

