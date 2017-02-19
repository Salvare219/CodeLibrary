#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<hash_map>
using namespace std;



int main()
{
//	freopen("1.txt","r",stdin);
	int n,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		sum+=temp;
	}
	n++;
	int ans=0;
	for(int i=1;i<=5;i++)
	{
		if((sum+i)%n!=1)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}