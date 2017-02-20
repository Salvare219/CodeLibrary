#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;




int num[2000];
int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		int sum=0,temp;
		for(int i=0;i<n;i++)
		{
			scanf("%d",num+i);
			sum^=num[i];
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			temp=sum^num[i];
			if(temp<num[i]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
