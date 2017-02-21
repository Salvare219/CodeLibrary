#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[100005];
map<int,int> p;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,time=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",num+i);
			p[num[i]]++;
			if(p[num[i]]==2)
			{
				p.clear();
				p[num[i]]++;
				time++;
			}
		}
		p.clear();
		printf("%d\n",time);
	}
    return 0;
}
