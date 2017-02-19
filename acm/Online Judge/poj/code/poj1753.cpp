#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 65536

int dx[5]={0,0,-1,1,0},dy[5]={1,-1,0,0,0},ans=-1;
void aoe(bool pic[][6],int x,int y)
{
	for(int i=0;i<5;i++)
		pic[x+dx[i]][y+dy[i]]=!pic[x+dx[i]][y+dy[i]];
}

bool exam(bool pic[][6])
{
	for(int i=1;i<5;i++)
		for(int j=1;j<5;j++)
			if((pic[i][j])!=(pic[1][1])) 
				return 0;
	return 1;
}

void gank(bool map[][4])
{
	bool pic[6][6]={0};
	for(int i=0;i<maxn;i++)
	{
		int step=0;
		for(int j=1;j<5;j++)
			for(int k=1;k<5;k++)
				pic[j][k]=map[j-1][k-1];
		for(int j=0;j<16;j++)
			if((i>>j)&1)
			{
				aoe(pic,j/4+1,j%4+1);
				step++;
			}
		if(exam(pic)) 
			if(ans==-1 || ans>step) ans=step;
	}
}


int main()
{
	bool map[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			char ch=getchar();
			if(ch=='w') map[i][j]=1;
			else map[i][j]=0;
		}
		getchar();
	}
	gank(map);
	if(ans==-1) printf("Impossible\n");
	else printf("%d\n",ans);
	return 0;
}