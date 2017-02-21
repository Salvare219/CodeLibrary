#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[100005],flag[100005],ans[100005][2];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,time=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	int sta=0,end,k=0;
	bool flag1=0;
	for(int i=0;i<n;i++)
	{
		ans[k][0]=sta;
		while(num[i]<=num[i+1]) i++;
		while(num[i]>=num[i+1]) 
		{
			if(num[i]>num[i+1]) sta=i+1;
			i++;
			if(i==n) 
			{
				flag1=1;
				break;
			}
		}
		end=i;
		ans[k++][1]=end;
		if(flag1) break;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=ans[i][0];j<=ans[i][1];j++)
		{
			if(flag[j]==0) flag[j]=2*(i+1);
			else flag[j]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(flag[y-1]-flag[x-1]<2) printf("Yes\n");
		else if(flag[x-1]%2 && flag[y-1]-flag[x-1]==2) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}