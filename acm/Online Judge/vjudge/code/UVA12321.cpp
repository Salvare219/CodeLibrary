#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


struct p
{
	int l,r;
}gas[100005];
bool cmp(struct p a,struct p b)
{
	if(a.l==b.l) return a.r>b.r;
	else return a.l<b.l;
}
int main()
{
	int l,g;
	while(scanf("%d%d",&l,&g))
	{
		if(l==0 && g==0) break;
		int x,r;
		for(int i=0;i<g;i++)
		{
			scanf("%d%d",&x,&r);
			gas[i].l=max(0,x-r);
			gas[i].r=min(l,x+r);
		}
		sort(gas,gas+g,cmp);
		if(gas[0].l>0) printf("-1\n");
		else
		{
			int time=0,len=0,flag=0,ma=0,m=0,i=0;
			while(i<g)
			{
				while(i<g && gas[i].l<=len)
				{
					flag=1;
					if(gas[i].r>ma) ma=gas[i].r;
					i++;
				}
				if(flag==0)
				{
					break;
				}
				len=ma;
				time=time+i-m-1;
				m=i;
				flag=0;
				if(l==len) break;
			}
			time+=g-i;
			if(len<l) printf("-1\n");
			else printf("%d\n",time);
		}
	}
    return 0;
}
