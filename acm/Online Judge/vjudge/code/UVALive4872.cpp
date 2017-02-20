#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   


struct e
{
	int he,to,len;
}ee[1000005];
int x[1001],y[1001],root[1001],n;
int find(int n)
{
	return (root[n]==n)? n:root[n]=find(root[n]);
}
double kruskal()
{
	double sum=0.0;
	int k=1,i=0;
	while(k<n)
	{
		int a=find(ee[i].he),b=find(ee[i].to);
		if(a!=b)
		{
			k++;
			sum=sum+sqrt((double)ee[i].len);
			root[b]=a;
		}
		i++;
	}
	return sum;
}
bool cmp(struct e a,struct e b)
{
	return a.len<b.len;
}
int main()
{
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
			root[i]=i;
		for(int i=0;i<n;i++)
			scanf("%d%d",x+i,y+i);
		int k=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int a=x[i]-x[j],b=y[i]-y[j];
				ee[k].he=i;ee[k].to=j;
				ee[k++].len=a*a+b*b;
			}
		sort(ee,ee+k,cmp);
		printf("%.2lf\n",kruskal());
	}
    return 0;
}
