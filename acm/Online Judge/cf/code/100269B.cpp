#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int num,id;
	double s;
	bool operator<(const node& a)const
	{
		return num==a.num?id<a.id:num>a.num;
	}
}s[15];

char a[15][105],v[15];
const char xxx[15]="Invalid";

int main()
{
	freopen("bad.in","r",stdin);
	freopen("bad.out","w",stdout);
	int n,m,i,j,l;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",a[i]),s[i].id=i;
	memcpy(a[i],xxx,sizeof(xxx)),s[i].id=i;
	for(i=0;i<m;i++)
	{
		scanf("%s",v);
		for(j=0,l=-1;j<n;j++)
			if(v[j]=='X')
			{
				if(l<0)
					l=j;
				else if(l<n)
					l=n;
			}
		if(l==-1)
			l=n;
		s[l].num++;
	}
	sort(s,s+n);
	for(i=0;i<=n;i++)
		s[i].s=round(1.0*s[i].num/m*10000)/100;
	for(i=0;i<=n;i++)
		printf("%s %.2f%%\n",a[s[i].id],s[i].s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
