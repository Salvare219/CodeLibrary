#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;


bool vis[20000];
int maze[1010][1010];
int st[1000000];
struct p
{
	int x,y,step;
}que[5000005];
void cal()
{
	for(int i=2;i<15000;i++)
	{
		int flag=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag) vis[i]=1;
	}
}
int dirx[4]={1,0,-1,0},diry[4]={0,1,0,-1};
void ini()
{
	int x=500,y=500;
	int len=1,time=1;
	maze[500][500]=1;
	st[1]=500500;
	vis[0]=1;
	for(int i=2;i<15000;time++)
	{
		len++;
		for(int j=0;j<len/2;j++)
		{
			x+=dirx[time%4];
			y+=diry[time%4];
			maze[x][y]=i;
			st[i]=x*1000+y;
			i++;
		}
	}

}
int bfs(int sta,int aim)
{
	int tail=0,front=1;
	que[0].x=sta/1000;
	que[0].y=sta%1000;
	que[0].step=0;
	bool pp[20000]={0};
	pp[maze[sta/1000][sta%1000]]=1;
	while(tail!=front)
	{
		int x=que[tail].x,y=que[tail].y,step=que[tail].step;
		if(maze[x][y]==aim) return step;
		tail++;
		for(int i=0;i<4;i++)
		{
			int dx=x+dirx[i],dy=y+diry[i];
			if(vis[maze[dx][dy]]==0 && pp[maze[dx][dy]]==0)
			{
				que[front].x=dx;
				que[front].y=dy;
				que[front++].step=step+1;
				pp[maze[dx][dy]]=1;
			}
		}
	}
	return -1;
}
int main()
{
	int t=0;
	cal();
	vis[0]=1;
	for(int i=15000;i<20000;i++)
	vis[i]=1;
	ini();
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("Case %d: ",++t);
		int c=bfs(st[a],b);
		if(c==-1) printf("impossible\n");
		else printf("%d\n",c);
	}
    return 0;
}
