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



int mes[1000000];
bool vis[1000000];
int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",mes+i);
	}
	int k=mes[n-1],ans=0;
	for(int i=n-2;i>-1;i--)
	{
		if(mes[i]<k)
		{
			k=mes[i];
		}
		else 
		{
			ans=i+1;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}