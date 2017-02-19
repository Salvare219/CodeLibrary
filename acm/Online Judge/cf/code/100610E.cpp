#include<bits/stdc++.h>
using namespace std;

int a[12];

int main()
{
	freopen("explicit.in","r",stdin);
	freopen("explicit.out","w",stdout);
	int i,j,k,s=0;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
			s^=a[i]|a[j];
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
			for(k=j+1;k<10;k++)
				s^=a[i]|a[j]|a[k];
	printf("%d\n",s);
	return 0;
}
