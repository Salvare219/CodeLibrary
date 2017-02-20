#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


int n,m;
char map[505][505];
int que[2][26000],tail=0,front,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
void bfs()
{
	int time=0;
	while(1)
	{
		time++;
		int tail=0,temp=0;
		if(front==0) break;
		for(int i=0;i<front;i++)
		{
			int x=que[(time-1)%2][i]/1000,y=que[(time-1)%2][i]%1000;
			if(map[x][y]>='a' && map[x][y]<='z') map[x][y]=map[x][y]-32;
		}
		while(tail!=front)
		{
			int x=que[(time-1)%2][tail]/1000,y=que[(time-1)%2][tail]%1000;
			char ch=map[x][y]+32;tail++;
			if(map[x][y]=='*') continue;
			for(int i=0;i<4;i++)
			{
				if(map[x+dx[i]][y+dy[i]]=='.') 
				{
					map[x+dx[i]][y+dy[i]]=ch;
					que[time%2][temp++]=(x+dx[i])*1000+y+dy[i];
				}
				else if(map[x+dx[i]][y+dy[i]]<='z' && map[x+dx[i]][y+dy[i]]>='a' && map[x+dx[i]][y+dy[i]]!=ch) map[x+dx[i]][y+dy[i]]='*';
			}
		}
		front=temp;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		front=tail=0;
		for(int i=0;i<n;i++)
			while(map[i+1][1]==0) scanf("%s",map[i+1]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]>='a' && map[i][j]<='z')
					que[0][front++]=i*1000+j;
		for(int i=1;i<=n;i++)
			map[i][0]='#';
		bfs();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]>='A' && map[i][j]<='Z') map[i][j]+=32;
		for(int i=0;i<n;i++)
			printf("%s\n",map[i+1]+1);
		putchar(10);
	}
    return 0;
}