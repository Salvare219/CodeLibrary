#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main()
{
	int n,l;
	double v;
	char temp[3];
	while(scanf("%d%d%lf",&n,&l,&v)!=EOF)
	{
		if(n==0) break;
		int sum=0,loc,dis;
		double t=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%*s%s",&loc,temp);
			if(temp[0]=='E') dis=l-loc;
			else dis=loc;
			sum+=dis;
			if(t<0 || dis/v>t) t=dis/v;
		}
		printf("%.2lf %d.00\n",t,sum);
	}
	return 0;
} 				    