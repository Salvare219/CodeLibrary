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
//	freopen("1.txt","r",stdin);
	char str[1005];
	scanf("%s",str);
	if(str[0]<='z' && str[0]>='a') str[0]-=32;
	printf("%s\n",str);
	return 0;
}