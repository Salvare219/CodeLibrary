#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
#define INF 0x7fffffff
#define mod 1000000009


long long b[3][3]={1,1,1,1,0,0,0,1,0};
long long f1[3]={0,1,2};
void mult(long long a[][3],long long b[][3],long long c[][3])
{
	long long d[3][3]={0};
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				d[i][j]=(d[i][j]+((a[i][k]%mod)*(b[k][j]%mod)))%mod;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			c[i][j]=d[i][j];
}
void powmat(long long a[][3],long long k)
{
	long long ii[3][3]={0};
	for(int i=0;i<3;i++)
		ii[i][i]=1;
	while(k)
	{
		if(k%2) mult(a,ii,ii);
		k/=2;
		mult(a,a,a);
	}
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			a[i][j]=ii[i][j];
}
long long f(long long k)
{
	if(k<=3) return f1[k-1];
	else 
	{
		long long c[3][3];
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				c[i][j]=b[i][j];
		powmat(c,k-3);
		long long sum=0;
		sum=(sum+(2*c[0][0])%mod+c[0][1]%mod)%mod;
		return (int)sum;
	}
}
int main()
{
	long long n;
	while(scanf("%lld",&n))
	{
		if(n==0) break;
		printf("%lld\n",f(n));
	}
    return 0;
}