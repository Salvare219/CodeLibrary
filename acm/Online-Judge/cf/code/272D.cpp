#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<hash_map>
using namespace std;



struct p
{
	int i,da;
}po[500000];

long long num[2][500000];

bool cmp(struct p a,struct p b)
{
	if(a.da==b.da) return a.i<b.i;
	else return a.da<b.da;
}

int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
	{
		scanf("%d",&po[i].da);
		po[i].i=i%n+1;
	}
	scanf("%d",&m);
	sort(po,po+2*n,cmp);
	int k=0;
	for(int i=0;i<2*n;i++)
	{
		if(po[i].da==po[i+1].da)
		{
			if(po[i].i==po[i+1].i)
			{
				num[1][k]++;
			}
			else num[0][k]++;
		}
		else 
		{
			num[0][k]++;
			num[0][k]=num[0][k]-num[1][k];
			k++;
		}
	}
	long long ans=1;
	long long ang=0,numl=0;
	for(int i=0;i<k;i++)
	{
		ang=1;numl=0;
		for(int j=1;j<=num[0][i];j++)
		{
			ang=(ang*(j%m))%m;
			numl++;
		}
		for(int j=1;j<=num[1][i];j++)
		{
			ang=ang*(((numl+2)*(numl+1)/2)%m);
			ang%=m;
			numl+=2;
		}
		ans=(ans*ang)%m;
	}
	printf("%I64d\n",ans);
	return 0;
}