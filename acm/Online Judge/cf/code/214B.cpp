#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;


int num[200000];
int ans[200000];
int temp[200000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	sort(num,num+n);
	for(int i=0;i<n;i++)
		temp[i]=num[i]%3;
	if(num[0]!=0) printf("-1\n");
	else 
	{
		int sum=0;
		for(int i=n-1;i>-1;i--)
			sum+=num[i];
		int mod=sum%3;
		if(mod==0) 
		{
			if(num[n-1]==0) printf("0");
			else
			{for(int i=n-1;i>-1;i--)
			{
				printf("%d",num[i]);
			}
			}
		}
		else 
		{
			int flag=-1;
			for(int i=0;i<n;i++)
				if(mod==temp[i])
				{
					flag=i;
					break;
				}
			if(flag!=-1) 
			{
				int kkkk=0;
				for(int i=n-1;i>-1;i--)
					if(i!=flag) temp[kkkk++]=num[i];
				if(temp[0]==0) printf("0");
				else
				{
					for(int i=0;i<n-1;i++)
						printf("%d",temp[i]);
				}
			}
			else 
			{
				int time=0,kk,laji[3],p=0;
				if(mod==1) kk=2;
				if(mod==2) kk=1;
				for(int i=0;i<n;i++)
				{
					if(temp[i]==kk) laji[p++]=i;
					if(p==2) break;
				}
				int kkkk=0;
				for(int i=n-1;i>-1;i--)
				{
					if(i!=laji[0] && i!=laji[1])
						temp[kkkk++]=num[i];
				}
				if(temp[0]==0) printf("0");
				else 
				{
					for(int i=0;i<n-2;i++)
						printf("%d",temp[i]);
				}
			}
		}
		putchar(10);
	}
	return 0;
}