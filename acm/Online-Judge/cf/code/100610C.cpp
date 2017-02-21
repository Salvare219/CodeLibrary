#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005],c[200005];
vector<int> v[200005];

inline void gao(int z,int x)
{
	int k,i,j;
	for(k=0;k<v[z].size();k++)
		if(!c[i=v[z][k]])
			for(j=0;j<z;j++,i=a[i],x=a[x])
				c[i]=c[x];
}

int main()
{
	freopen("commuting.in","r",stdin);
	freopen("commuting.out","w",stdout);
	int n,i,j,k;
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		if(!b[i])
		{
			for(j=a[i],k=1;j!=i;j=a[j],k++);
			for(j=a[i],b[i]=k;j!=i;b[j]=k,j=a[j]);
			v[k].push_back(i);
		}
	for(i=1;i<=n;i++)
		if(!c[i])
		{
			for(j=a[c[i]=i];j!=i;c[j]=j,j=a[j]);
			for(k=b[i];k<=n;k+=b[i])
				gao(k,i);
		}
	for(i=1;i<=n;i++)
		printf("%d%c",c[i],"\n "[i<n]);
	return 0;
}
