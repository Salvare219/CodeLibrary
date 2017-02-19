#include<stdio.h>


int main()
{
	int n,m,k=0,poi[2][3],x=0,y=0;
	char map[101][101]={0};
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",map[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='*') 
			{
				poi[0][k]=i;
				poi[1][k]=j;
				k++;
			}
		}
	for(int i=1;i<3;i++)
	{
		if(poi[0][0]==poi[0][i]) 
		{
			m=i;
			x=1;
		}
		if(poi[1][0]==poi[1][i])
		{
			n=i;
			y=1;
		}
	}
	if(x==1) 
	{
		if(m==1) m=2;
		else if(m==2) m=1;
	}
	else m=0;
	if(y==1)
	{
		if(n==1) n=2;
		else if(n==2) n=1;
	}
	else n=0;
	printf("%d %d\n",poi[0][m]+1,poi[1][n]+1);
}
