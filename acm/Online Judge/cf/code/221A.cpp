#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		if(i==0) printf("%d ",n);
		else printf("%d ",i);
	putchar(10);
	return 0;
}
