#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

stack<char> q;
stack<int> val;
bool a[200005],b[200005];
int s[200005],sn,pn;
char c[5005],p[5005];

inline void add(char x)
{
	switch(x)
	{
	case '(':
		q.push(x);
		break;
	case ')':
		while(q.top()!='(')
		{
			p[pn++]=q.top();
			q.pop();
		}
		q.pop();
		break;
	case '-':
		q.push(x);
		break;
	case '*':
		while(q.top()=='*'||q.top()=='-')
		{
			p[pn++]=q.top();
			q.pop();
		}
		q.push('*');
		break;
	case '+':
		while(q.top()=='+'||q.top()=='*'||q.top()=='-')
		{
			p[pn++]=q.top();
			q.pop();
		}
		q.push(x);
		break;
	default:
		p[pn++]=x;
		break;
	}
}

int main()
{
	int n,m,x,y,T=0,i;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		sn=pn=0;
		for(scanf("%d",&x),i=0;i<x;i++)
		{
			scanf("%d",&y);
			a[y]=1;
		}
		for(scanf("%d",&x),i=0;i<x;i++)
		{
			scanf("%d",&y);
			b[y]=1;
		}
		scanf("%s",c);
		add('(');
		for(i=0;i<m;i++)
			add(c[i]);
		add(')');
		for(i=0;i<pn;i++)
		{
			switch(p[i])
			{
			case 'A':
				val.push(3);
				break;
			case 'B':
				val.push(6);
				break;
			case '-':
				x=val.top();
				val.pop();
				val.push(~x);
				break;
			case '*':
				x=val.top();
				val.pop();
				y=val.top();
				val.pop();
				val.push(x&y);
				break;
			case '+':
				x=val.top();
				val.pop();
				y=val.top();
				val.pop();
				val.push(x|y);
				break;
			}
		}
		x=val.top();
		while(!val.empty())
			val.pop();
		for(i=1;i<=n;i++)
		{
			if(a[i]&&!b[i]&&(x&(1<<0)))
				s[sn++]=i;
			if(a[i]&&b[i]&&(x&(1<<1)))
				s[sn++]=i;
			if(!a[i]&&b[i]&&(x&(1<<2)))
				s[sn++]=i;
			if(!a[i]&&!b[i]&&(x&(1<<3)))
				s[sn++]=i;
		}
		printf("Case %d: %d",++T,sn);
		for(i=0;i<sn;i++)
			printf(" %d",s[i]);
		puts("");
	}
	return 0;
}
