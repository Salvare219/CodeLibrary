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
	int a,c,b,temp;
	scanf("%d%d%d",&a,&b,&c);
	if(c<b) swap(c,b);
	if(c<a) swap(c,a);
	if(a>b) swap(a,b);
	temp=b*c+(a-1)*c+(b-1)*(a-1);
	printf("%d\n",temp);
    return 0;
}