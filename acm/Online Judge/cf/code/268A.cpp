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
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&col[i][0],&col[i][1]);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(col[i][1]==col[j][0])
			{
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}