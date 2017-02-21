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
	int n;
	scanf("%d%s",&n,str);
	int time=0;
	for(int i=1;i<n;i++)
	{
		if(str[i]==str[i-1]) time++;
	}
	printf("%d\n",time);
	return 0;
}