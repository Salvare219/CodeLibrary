#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct fl
{
	int num,day;
}floo[1005];
int cmp(void const *a,void const *b)
{
	struct fl *c=(struct fl*)a;
	struct fl *d=(struct fl*)b;
	return (c->day>d->day)?1:-1;
}
int main()
{
	int n,rain[1005],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",rain+i);
		floo[i].num=i;
		floo[i].day=rain[i];
	}
	qsort(floo,n,sizeof(floo[0]),cmp);
	for(i=0;i<n;i++)
	{
		if(floo[i].num==0 || floo[i].num==n-1) 
			break;
		else
		{
			rain[floo[i].num]=0;
			if(rain[floo[i].num-1]==0 || rain[floo[i].num+1]==0) 
				break;
		}
	}
	printf("%d\n",floo[i].day);
	return 0;
}