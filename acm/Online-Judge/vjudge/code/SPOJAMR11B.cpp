#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


bool peo[151][151];
int tot(int x[],int y[])
{
	return abs(x[0]*y[1]-x[1]*y[0]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(peo,0,sizeof(peo));
		int n;
		char str[2];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			if(str[0]=='C')
			{
				int x,y,r;
				scanf("%d%d%d",&x,&y,&r);
				x+=50;y+=50;
				for(int i=x-r;i<=x+r;i++)
					for(int j=y-r;j<=y+r;j++)
					{
						int d1=i-x,d2=j-y;
						if(d1*d1+d2*d2<=r*r) peo[i][j]=1;
					}
			}
			else if(str[0]=='S')
			{
				int x,y,l;
				scanf("%d%d%d",&x,&y,&l);
				x+=50;y+=50;
				for(int i=x;i<=x+l;i++)
					for(int j=y;j<=y+l;j++)
						peo[i][j]=1;
			}
			else
			{
				int coo[3][2],dx[2],dy[2];
				for(int i=0;i<3;i++)
				{
					scanf("%d%d",&coo[i][0],&coo[i][1]);
					coo[i][0]+=50;coo[i][1]+=50;
					if(i!=0) 
					{
						dx[i-1]=coo[i][0]-coo[0][0];
						dy[i-1]=coo[i][1]-coo[0][1];
					}
				}
				int S=tot(dx,dy),mx=coo[0][0],ix=coo[0][0],my=coo[0][1],iy=coo[0][1];
				for(int i=1;i<3;i++)
				{
					if(coo[i][0]>mx) mx=coo[i][0];
					if(coo[i][1]>my) my=coo[i][1];
					if(coo[i][0]<ix) ix=coo[i][0];
					if(coo[i][1]<iy) iy=coo[i][1];
				}
				for(int i=ix;i<=mx;i++)
					for(int j=iy;j<=my;j++)
					{
						int sum=0;
						for(int k=0;k<3;k++)
						{
							dx[0]=coo[k][0]-i;
							dx[1]=coo[(k+1)%3][0]-i;
							dy[0]=coo[k][1]-j;
							dy[1]=coo[(k+1)%3][1]-j;
							sum+=tot(dx,dy);
						}
						if(S==sum) peo[i][j]=1;
					}
			}
		}
		int time=0;
		for(int i=0;i<151;i++)
			for(int j=0;j<151;j++)
				if(peo[i][j]) time++;
		printf("%d\n",time);
	}
    return 0;
}