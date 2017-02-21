#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<ctime>
using namespace std;



int dex[2][100005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(dex[0][temp]==0) dex[0][temp]=i+1;
		dex[1][temp]=n-i;
	}
	long long a=0,b=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&temp);
		a+=dex[0][temp];
		b+=dex[1][temp];
	}
	printf("%I64d %I64d\n",a,b);
    return 0;
}