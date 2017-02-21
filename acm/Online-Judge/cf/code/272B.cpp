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



long long num[1000005];
long long con[1000005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,sum=0,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int an=1;
		scanf("%d",&temp);
		while(temp!=1)
		{
			if(temp%2) 
			{
				temp--;
				an++;
			}
			else temp/=2;
		}
		num[i]=an;
	}
	int k=0;
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		if(num[i]!=num[i+1])
		{
			con[k]++;
			k++;
		}
		else
		{
			con[k]++;
		}
	}
	long long ans=0;
	for(int i=0;i<k;i++)
	{
		ans=ans+con[i]*(con[i]-1)/2;
	}
	printf("%I64d\n",ans);
	return 0;
}