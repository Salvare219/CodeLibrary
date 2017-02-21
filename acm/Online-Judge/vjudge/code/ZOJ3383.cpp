#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



char str[100],lib[]="0123456789ABCDEF";
int maze[500][500];
int cha(char ch)
{
	return strchr(lib,ch)-lib;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int w,h;
	while(scanf("%dx%d",&w,&h)==2)
	{
		int r,g,b;
		long long tot=0;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				scanf("%s",str);
				r=cha(str[1])*16+cha(str[2]);
				g=cha(str[3])*16+cha(str[4]);
				b=cha(str[5])*16+cha(str[6]);
				maze[i][j]=(11*r+16*g+5*b)/32;
				tot+=maze[i][j];
			}
		tot/=w*h;
		tot=(192 + 2 * tot) / 3;
		char ch;
		printf("%dx%d\n",w,h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				if(maze[i][j]<tot) ch='9';
				else ch=' ';
				if(j) printf(" %c",ch);
				else putchar(ch);
			}
			putchar(10);
		}
	}
    return 0;
}