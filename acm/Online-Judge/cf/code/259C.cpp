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



char num[100005];
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%s",num);
	int time=0;
	if(strchr(num,'0'))
	{
		for(int i=0;num[i];i++)
		{
			if(num[i]=='0' && time==0)
			{
				time++;
			}
			else 
			{
				putchar(num[i]);
			}
		}
		putchar(10);
	}
	else 
	{
		num[strlen(num)-1]=0;
		printf("%s\n",num);
	}
    return 0;
}
