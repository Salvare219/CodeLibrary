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
	int num[20];
	while(scanf("%d",&n))
	{
		if(n==0) break;
		int temp,sum=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%d",num+i);
		}
		if(n%2) printf("1\n");
		else 
		{
			bool flag=0;
			sort(num,num+n);
			for(int i=0;i<n;i+=2)
			{
				if(num[i]!=num[i+1]) 
				{
					flag=1;
					break;
				}
			}
			if(flag) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
