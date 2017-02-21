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



int col[1000][2];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int ma=min(n,m)+1;
	printf("%d\n",ma);
	for(int i=0;i<ma;i++)
		printf("%d %d\n",ma-1-i,i);
	return 0;
}