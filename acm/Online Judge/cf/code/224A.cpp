#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;


int main()
{
//	freopen("1.txt","r",stdin);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x=a*b/c,y=b*c/a,z=a*c/b;
	printf("%d\n",4*(int)(sqrt((double)x)+sqrt((double)z)+sqrt((double)y)));
	return 0;
}