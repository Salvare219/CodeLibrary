#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define INF 0x7fffffff


int num[105];
void cal()
{
	num[1]=7;num[2]=27;
	for(int i=3;i<=10;i++)
		num[i]=70;
	num[11]=270;
	for(int i=12;i<100;i++)
		num[i]=700;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	cal();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",num[n]);
	}
    return 0;
}