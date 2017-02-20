#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int a[400],b[400];
int ans[900006][2];
int k;
int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(b[j]==a[i])
			{
				swap(b[j],b[j-1]);
				ans[k][0]=j+1;
				ans[k++][1]=j;
			}
		}
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	{
		printf("%d %d\n",ans[i][1],ans[i][0]);
	}
	return 0;
}