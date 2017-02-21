#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int row[2000],col[2000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",row+i);
		for(int i=0;i<m;i++) scanf("%d",col+i);
		long long time=0,ans=0;
		sort(row,row+n);
		int a=0;
		for(int i=n-1;i>-1;i--)
		{
			if(row[i]==0) break;
			sort(col+a,col+m);
			for(int j=m-1;j>-1;j--)
			{
				if(col[j]==0) 
				{
					a=j+1;
					break;
				}
				if(row[i] && col[j])
				{
					row[i]--;col[j]--;
					time++;
				}
			}
			time+=row[i];
		}
		for(int i=0;i<m;i++)
			time+=col[i];
		printf("%lld\n",time);
	}
    return 0;
}
