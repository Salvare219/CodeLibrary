#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 1000

struct peo
{
	double a,b;
}ren[maxn+10];
double hei[maxn+10]={0},t1,t2,k;
int num[maxn+10];

double calhei(double h,double j)
{
	return h*t1*((100.0-k)/100.0)+j*t2;
}

int main()
{
	int n,tempd;
	double tempf;
	scanf("%d%lf%lf%lf",&n,&t1,&t2,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&ren[i].a,&ren[i].b);
		double temp1=calhei(ren[i].a,ren[i].b),temp2=calhei(ren[i].b,ren[i].a);
		hei[i]=(temp1>temp2)?temp1:temp2;
		num[i]=i;
	}
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
		{
			if(hei[j+1]>hei[j]) 
			{
				tempf=hei[j];
				hei[j]=hei[j+1];
				hei[j+1]=tempf;
				tempd=num[j];
				num[j]=num[j+1];
				num[j+1]=tempd;
			}
		}
	for(int i=0;i<n;i++)
		printf("%d %.2lf\n",num[i]+1,hei[i]);
	return 0;
}