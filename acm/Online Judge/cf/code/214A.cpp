#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;


int main()
{
	int n,m,time=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
		{
			if(i*i+j==n && j*j+i==m)
			{
				time++;
			}
		}
	printf("%d\n",time);
	return 0;
}