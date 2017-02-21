#include<bits/stdc++.h>
using namespace std;

int p[40],pn;
long long a[40],t[200005][40],lz[200005][40],mod;
bool lx[200005];

long long pw(long long m,long long n)
{
	long long s=1;
	while(n)
	{
		if(n&1)
			s=(s*m)%mod;
		n>>=1,m=(m*m)%mod;
	}
	return s;
}

inline void down(int& l,int& m,int& r,int& rt,int& ll,int& rr)
{
	for(int i=0;i<pn;i++)
	{
		t[ll][i]+=lz[rt][i]*(m-l+1);
		t[rr][i]+=lz[rt][i]*(r-m);
		lz[ll][i]+=lz[rt][i];
		lz[rr][i]+=lz[rt][i];
		lz[rt][i]=0;
	}
	lx[rt]=0;lx[ll]=lx[rr]=1;
}
void update(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R)
	{
		for(int i=0;i<pn;i++)
		{
			t[rt][i]+=a[i]*(r-l+1);
			lz[rt][i]+=a[i];
			lx[rt]=1;
		}
		return;
	}
	int m=(l+r)/2,ll=rt*2,rr=rt*2+1,i;
	if(lx[rt])
		down(l,m,r,rt,ll,rr);
	if(L<=m)
		update(L,R,l,m,ll);
	if(R>m)
		update(L,R,m+1,r,rr);
	for(i=0;i<pn;i++)
		t[rt][i]=t[ll][i]+t[rr][i];
}
void query(int L,int R,int l,int r,int rt)
{
	if(l>=L&&r<=R)
	{
		for(int i=0;i<pn;i++)
			a[i]+=t[rt][i];
		return;
	}
	int m=(l+r)/2,ll=rt*2,rr=rt*2+1;
	if(lx[rt])
		down(l,m,r,rt,ll,rr);
	if(L<=m)
		query(L,R,l,m,ll);
	if(R>m)
		query(L,R,m+1,r,rr);
}

int main()
{
	int T,n,m,i,j,c,l,r,w;
	long long s;
	for(i=2;i<=150;i++)
	{
		for(j=2;j<i;j++)
			if(i%j==0)
				break;
		if(j>=i)
			p[pn++]=i;
	}
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		memset(t,0,sizeof(t));
		memset(lz,0,sizeof(lz));
		memset(lx,0,sizeof(lx));
		while(m--)
		{
			scanf("%d%d%d%d",&c,&l,&r,&w);
			if(c==0)
			{
				memset(a,0,sizeof(a));
				if(l<=r)
					query(l,r,1,n,1);
				else
					query(l,n,1,n,1),query(1,r,1,n,1);
				for(mod=w,i=0,s=1;i<pn;i++)
					s=s*pw(p[i],a[i])%mod;
				printf("%I64d\n",s);
			}
			else
			{
				for(c--,i=0;i<pn;i++)
				{
					j=0;
					while(w%p[i]==0)
						w/=p[i],j++;
					a[i]=c?-j:j;
				}
				if(l<=r)
					update(l,r,1,n,1);
				else
					update(l,n,1,n,1),update(1,r,1,n,1);
			}
		}
	}
	return 0;
}
