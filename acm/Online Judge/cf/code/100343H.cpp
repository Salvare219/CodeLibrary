#include<bits/stdc++.h>
using namespace std;

vector<int> v[100005];
char a[100005],s[100005];
int n,t[100005][2],tt;

inline int cal(int st)
{
	int x=st,y,t=0;
	char f;
	for(;;)
	{
		t+=s[x]=='t';
		y=x-1;
		if(y<0)
			y+=n;
		if(a[y]=='$')
			return t;
		f=(s[x]=='t'&&a[y]=='+')||(s[x]=='f'&&a[y]=='-')?'t':'f';
		if(y==st)
			return f==s[y]?t:-1;
		s[x=y]=f;
	}
	return -1;
}

int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int x,y,i,j,k;
	bool f;
	for(scanf("%d",&n),f=i=0;i<n;i++)
	{
		scanf(" %c",&a[i]);
		if(a[i]=='$')
		{
			f=1;
			scanf("%d",&x);
			v[x].push_back(i);
		}
	}
	if(!f)
	{
		s[n-1]='t';
		if(cal(n-1)>=0)
		{
			printf("consistent\n%s\n",s);
			return 0;
		}
		s[n-1]='f';
		if(cal(n-1)>=0)
		{
			printf("consistent\n%s\n",s);
			return 0;
		}
		puts("inconsistent");
		return 0;
	}
	for(tt=i=0;i<=100000;i++)
		for(k=v[i].size(),j=0;j<k;j++)
		{
			x=v[i][j];
			s[x]='t';
			y=cal(x);
			t[i][0]+=y;
			s[x]='f';
			y=cal(x);
			t[i][1]+=y;
			tt+=y;
		}
	for(i=0;i<=100000;i++)
		if(tt+t[i][0]-t[i][1]==i)
		{
			for(k=v[i].size(),j=0;j<k;j++)
			{
				x=v[i][j];
				s[x]='t';
				y=cal(x);
			}
			printf("consistent\n%s\n",s);
			return 0;
		}
	puts("inconsistent");
	return 0;
}
