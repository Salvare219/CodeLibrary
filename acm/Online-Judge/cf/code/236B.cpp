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


int d[1000005];
void cal()
{
	for(int i=1;i<1000003;i++)
		for(int j=i;j<1000003;j+=i)
			d[j]++;
}
int main()
{
	cal();
	int a,b,c;
	int ans=0;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			for(int k=1;k<=c;k++)
			{
				ans=(ans+d[i*j*k])%1073741824;
			}
	printf("%d\n",ans);
	return 0;
}
