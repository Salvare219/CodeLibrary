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
#define INF 0x7fffffff


char str[3][300];
int main()
{
	int t,d,n;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<3;i++)
			scanf("%s",str[i]);
		printf("%s will survive\n",str[1]);
 	}
    return 0;
}