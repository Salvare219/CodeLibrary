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
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",num+i);
		sort(num,num+n);
		if(n%2)
		{
			sum=num[0]-1;
			for(int i=1;i<n;i+=2)
				sum^=(num[i+1]-num[i]-1);
		}
		else 
		{
			for(int i=0;i<n;i+=2)
				sum^=(num[i+1]-num[i]-1);
		}
		if(sum) printf("Georgia will win\n");
		else printf("Bob will win\n");
	}
	return 0;
}