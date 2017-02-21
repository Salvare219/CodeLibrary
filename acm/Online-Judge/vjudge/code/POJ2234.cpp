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
	int n;
	while(scanf("%d",&n)==1)
	{
		int sum=-1,temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(sum==-1) sum=temp;
			else sum^=temp;
		}
		if(sum) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
