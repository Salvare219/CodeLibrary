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



int col[1000][2];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ans=ans+(n-i)*(i+1)-i;
	}
	printf("%d\n",ans);
	return 0;
}