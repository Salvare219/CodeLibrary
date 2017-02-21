#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;



int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		bool flag=1;
		int temp;
		scanf("%d",&temp);
		for(int i=3;i<10000;i++)
		{
			if(temp*i==(i-2)*180) 
			{
				flag=0;
				break;
			}
		}
		if(flag==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}