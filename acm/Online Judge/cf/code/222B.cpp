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
#define INF 0x7fffffff


int maze[1005][1005];
int row[1005],col[1005];
int main()
{
//	freopen("1.txt","r",stdin);
	int r,c,q;
	scanf("%d%d%d",&r,&c,&q);
	for(int i=0;i<r;i++)
		row[i]=i;
	for(int i=0;i<c;i++)
		col[i]=i;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	char ch[10];
	int x,y;
	for(int i=0;i<q;i++)
	{
		scanf("%s%d%d",ch,&x,&y);
		if(ch[0]=='c')
		{
			int temp=col[x-1];
			col[x-1]=col[y-1];
			col[y-1]=temp;
		}
		else if(ch[0]=='r')
		{
			int temp=row[x-1];
			row[x-1]=row[y-1];
			row[y-1]=temp;
		}
		else 
		{
			printf("%d\n",maze[row[x-1]][col[y-1]]);
		}
	}
    return 0;
}