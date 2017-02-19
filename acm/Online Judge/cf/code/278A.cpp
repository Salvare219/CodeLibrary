#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[500];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",num+i);
		num[i+n]=num[i];
	}
	scanf("%d%d",&x,&y);
	if(x>y) swap(x,y);
	int sum=0;
	for(int i=x;i<y;i++)
		sum+=num[i];
	int sum1=0;
	for(int i=y;i<x+n;i++)
		sum1+=num[i];
	printf("%d\n",min(sum,sum1));
	return 0;
}