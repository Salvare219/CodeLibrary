#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>gra[520];
int nn,mm;
bool use[520];
int phx[520],phy[520],p[520];
int q[520];
bool relable()
{
for(int i=1;i<=nn;i++)phx[i]=0;
for(int i=1;i<=mm;i++)phy[i]=0;
int tail=0,front=0,s,y;
bool f=0;
for(int i=1;i<=nn;i++)
if(!use[i])q[tail++]=i;
while(tail!=front)
{
s=q[front++];
for(int i=0;i<gra[s].size();i++)
if(!phy[y=gra[s][i]])
{
phy[y]=phx[s]+1;
if(!p[y])f=1;
else phx[p[y]]=phy[y]+1,q[tail++]=p[y];
}
}
return f;
}
bool find(int s)
{
int y;
for(int i=0;i<gra[s].size();i++)
if(phy[y=gra[s][i]]==phx[s]+1)
{
phy[y]=0;
if(!p[y]||find(p[y]))return p[y]=s,1;
}
return 0;
}
int Hopcroft_Karp()
{
int ans=0;
memset(use,0,sizeof(use));
memset(p,0,sizeof(p));
while(relable())
for(int i=1;i<=nn;i++)
if(!use[i]&&find(i))use[i]=1,ans++;
return ans;
}

int a[35][35];

int main()
{
int n,m,k,i,j,x,y;
while(scanf("%d%d%d",&m,&n,&k)==3)
{
memset(a,0,sizeof(a));
for(nn=mm=i=0;i<n;i++)
for(j=0;j<m;j++)
a[i][j]=(i+j)&1?++mm:++nn;
for(i=0;i<k;i++)
{
scanf("%d%d",&x,&y);
a[x-1][y-1]=0;
}
if((n*m-k)&1)
{
puts("NO");
continue;
}
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
if(!(x=a[i][j]))
continue;
if(y=a[i+1][j])
{
if((i+j)&1)
swap(x,y);
gra[x].push_back(y);
if((i+j)&1)
swap(x,y);
}
if(y=a[i][j+1])
{
if((i+j)&1)
swap(x,y);
gra[x].push_back(y);
if((i+j)&1)
swap(x,y);
}
}
puts(n*m-k==Hopcroft_Karp()*2?"YES":"NO");
for(i=1;i<=nn;i++)
gra[i].clear();
}
return 0;
}