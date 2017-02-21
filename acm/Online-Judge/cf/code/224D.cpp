#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char s[200005],t[200005];
int l[200005],r[200005],last[200];
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%s%s",s,t);
	int cont=0;
	for(int i=0;s[i];i++)
	{
		if(t[cont] && s[i]==t[cont])
		{
			l[i]=cont;
			last[s[i]]=cont;
			cont++;
		}
		else l[i]=last[s[i]];
	}
	cont=strlen(t);
	for(int i='a';i<='z';i++)
		last[i]=cont;
	int lens=strlen(s);
	cont--;
	for(int i=lens-1;i>-1;i--)
	{
		if(cont>-1 && s[i]==t[cont])
		{
			r[i]=cont;
			last[s[i]]=cont;
			cont--;
		}
		else r[i]=last[s[i]];
	}
	bool flag=1;
	for(int i=0;s[i];i++)
		if(l[i]<r[i]) 
		{
			flag=0;
			break;
		}
	if(flag) puts("Yes");
	else puts("No");
	return 0;
}