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
	int t,d,n;
	scanf("%d",&t);
	while(t--)
	{
		double fee;
		scanf("%d%d",&d,&n);
		if(d<=3) fee=11;
		else if(d<=10) fee=11+(d-3)*2.5;
		else  fee=11+(d-10)*3.75+2.5*7;
		fee=fee+2.5*((double)n/4.0);
		int las,orc;
		if(fee-(int)fee>=0.5) las=(int)fee+1;
		else las=(int)fee;
		if(d<=3) fee=11;
		else if(d<=10) fee=11+(d-3)*2;
		else fee=11+(d-10)*3+2*7;
		fee=fee+((double)n/5.0)*2;
		if(fee-(int)fee>=0.5) orc=(int)fee+1;
		else orc=(int)fee;
		printf("%d\n",las-orc);
 	}
    return 0;
}