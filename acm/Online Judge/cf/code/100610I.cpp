#include<bits/stdc++.h>
using namespace std;

char a[1005],b[1005];
struct node
{
	bool p[30];
	int tot,tme,r;
}c[305];

inline int getI(int& z)
{
	int s=0,k=1;
	while(a[--z]==' ');
	for(;a[z]!=' ';z--)
		s+=k*(a[z]-'0'),k*=10;
	return a[z+1]=='+'?1:a[z+1]=='-'||a[z+1]=='.'?0:s;
}

int main()
{
	freopen("ideal.in","r",stdin);
	freopen("ideal.out","w",stdout);
	char *x=a,*y=b;
	int T=0,P=0,i,j,k,l[30];
	double V=0,O=0,E=0,U=0,I[30],N=0;
	while(gets(x)&&x[0]!='-')
		swap(x,y);
	for(i=4;y[i]!='=';i++)
		if(y[i]!=' ')
			P=y[i]-'A'+1;
	while(gets(a))
	{
		k=strlen(a);
		c[T].r=getI(k);
		c[T].tme=getI(k);
		c[T].tot=getI(k);
		for(i=P;i--;)
			c[T].p[i]=getI(k);
		T++;
	}
	for(i=0;i<P;i++)
		I[i]=0,l[i]=-1;
	for(i=T,k=c[T-1].tot;i--;)
	{
		if(c[i].tot==0)
			V+=1;
		if(c[i].tot==P)
			O+=1;
		if(c[i].tot-k>1)
			E+=c[i].tot-k-1;
		k=c[i].tot;
		for(j=0;j<P;j++)
		{
			if(c[i].p[j]&&l[j]<0)
				l[j]=c[i].r;
			if(!c[i].p[j]&&c[i].r<l[j])
				I[j]+=1;
		}
	}
	for(i=0;i<P;i++)
		if(l[i]<0)
			U+=1;
	for(i=0;i<P;i++)
		N+=I[i]/=T;
	N/=P;
	N+=1.03*(V/=T);N+=3.141*(O/=T);N+=2.171*(E/=P);N+=1.414*(U/=P);
	printf("Vainness = %.3f\n",V);
	printf("Oversimplification = %.3f\n",O);
	printf("Evenness = %.3f\n",E);
	printf("Unsolvability = %.3f\n",U);
	for(i=0;i<P;i++)
		printf("Instability %d = %.3f\n",i+1,I[i]);
	printf("Negidealness = %.3f\n",N);
	return 0;
}
