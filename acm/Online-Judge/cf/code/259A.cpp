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



char num[10000];
int main()
{
//	freopen("1.txt","r",stdin);
	bool flag=0;
	for(int i=0;i<8;i++)
	{
		scanf("%s",num);
		for(int j=1;num[j];j++)
		{
			if(num[j]==num[j-1]) 
			{
				flag=1;
				break;
			}
		}
		if(flag) 
		{
			break;
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");
    return 0;
}
