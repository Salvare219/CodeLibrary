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



char str[1000];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,t;
	scanf("%d%d%s",&n,&t,str);
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(str[j]=='B' && str[j+1]=='G') 
			{
				str[j]='G';
				str[j+1]='B';
				j++;
			}
		}
	}
	printf("%s\n",str);
	return 0;
}