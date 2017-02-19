#include<bits/stdc++.h>
using namespace std;

const int lib[10][2]={0,1,1,1,1,1,1,1,2,2,1,1,2,2,2,1,2,1,3,3};

int main()
{
	int T,c,l;
	long long w,s1,s2;
	for(scanf("%d",&T);T--;)
	{
		scanf("%I64d%d",&w,&c);
		if(w%1000)
		{
			puts("0");
			continue;
		}
		w/=1000,c++;
		s1=0,s2=1;
		while(c--)
		{
			l=w%10;
			w/=10;
			s1+=lib[l][0];
			s2*=lib[l][1];
		}
		if(w&&(l==1||l==4))
			s2=s2/lib[l][1]*(lib[l][1]+1);
		s1+=w*2;
		printf("%I64d %I64d\n",s1,s2);
	}
	return 0;
}
