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
	int n,temp,s1=0,s2=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%*d",&temp);
		if(s1+temp>s2+500) putchar('G'),s2+=1000-temp;
		else putchar('A'),s1+=temp;
	}
	putchar(10);
    return 0;
}

