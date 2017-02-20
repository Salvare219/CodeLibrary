#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sa[200050],tsa[400050],height[200050];
int rank[200050],tsb[400050],bas[200050];
char str[200050];
int n;
void get_sa()
{
	int i,j,m=128,p,*x=tsa,*y=tsb;
	memset(tsa,0,sizeof(tsa));
	memset(tsb,0,sizeof(tsb));
	for(i=0;i<m;i++) bas[i]=0;
	for(i=0;i<n;i++) bas[x[i]=str[i]]++;
	for(i=1;i<m;i++) bas[i]+=bas[i-1];
	for(i=n-1;i>-1;i--) sa[--bas[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p)
	{
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++) bas[i]=0;
		for(i=0;i<n;i++) bas[x[y[i]]]++;
		for(i=1;i<m;i++) bas[i]+=bas[i-1];
		for(i=n-1;i>=0;i--) sa[--bas[x[y[i]]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j])?p-1:p++;
	}

	for(i=0;i<n;i++) rank[sa[i]]=i;
 	for(i=0,j=0;i<n;height[rank[i++]]=j)
 		if(rank[i]) for(j?j--:0,p=sa[rank[i]-1];str[i+j]==str[p+j];j++);
}
int main()
{
    scanf("%d",&n);
    scanf("%s%s",str,str+n+1);
    str[n]='@';n<<=1;n++;get_sa();
    int ans=0,f=0,d=(n-1)>>1;
    for(int i=1;i<n;i++)
        if((sa[i]<d && sa[i-1]>d) || (sa[i]>d && sa[i-1]<d))
        {
            if(ans<height[i]) ans=height[i],f=sa[i];
        }
    for(int i=0;i<ans;i++)
        putchar(str[f+i]);putchar(10);
    return 0;
}
