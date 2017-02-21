#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
 //   freopen("1.txt","r",stdin);
	int a,b,temp;
	double k=(1+sqrt(5.0))/2;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a>b) swap(a,b);
		temp=b-a;
		temp=temp*k;
		if(temp==a) putchar('0');
		else putchar('1');
		putchar(10);
	}
    return 0;
}

