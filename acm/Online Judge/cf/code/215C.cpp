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


int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	if(s%2==0) printf("0\n");
	else
	{
		int a=(n-1)/2,b=(m-1)/2,now;
		long long sum=0;
		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
			{
				now=(2*i+1)*(2*j+1);
				if(now>s) break;
				for(int k=0;k<=a;k++)
				{
					if(now==s)
					{
						if(k<=i) 
						{
							sum+=(j+1)*max(0,(n-2*i))*max(0,(m-2*j));
		//					if(max(0,(n-2*i))*max(0,(m-2*j))) printf("%d %d %d\n",i,j,k);
						}
					}
					else
					{
						if(k<=i) 
						{
							if((s-now)%(2*(2*k+1))==0)
							{
								int temp=(s-now)/(2*(2*k+1))+j;
								sum+=max(0,(n-2*i))*max(0,(m-2*temp));
	//							if(max(0,(n-2*i))*max(0,(m-2*temp))) printf("%d %d %d\n",i,j,k);
							}
						}
						else 
						{
							if(s/(2*k+1)>=(2*j+1)) 
							{
								if(s%(2*k+1)==0)
								{
									sum+=max(0,(n-2*k))*max(0,(m-s/(2*k+1)+1));
	//								if(max(0,(n-2*k))*max(0,(m-s/(2*k+1)+1))) printf("%d %d %d\n",i,j,k);
								}
							}
							else 
							{
								int temp=s-now;
								if(temp%(2*(k-i))==0 && (temp/(2*(k-i)))%2)
								{
									sum+=max(0,(n-2*k))*max(0,(m-2*j));
	//								if(max(0,(n-2*k))*max(0,(m-2*j))) printf("%d %d %d\n",i,j,k);
								}
							}
						}
					}
				}
			}
		printf("%I64d\n",sum);
	}
    return 0;
}