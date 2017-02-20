#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sa[1050],tsa[2050],height[1050];
int rank[1050],tsb[2050],bas[1050];
char str[1050];
int n;
void get_sa()
{
	int i,j,m=128,p,*x=tsa,*y=tsb;
//	memset(tsa,-1,sizeof(tsa));
//	memset(tsb,-1,sizeof(tsb));
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
		for(i=n-1;i>-1;i--) sa[--bas[x[y[i]]]]=y[i];
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j])?p-1:p++;
	}

	for(i=0;i<n;i++) rank[sa[i]]=i;
 	for(i=0,j=0;i<n;height[rank[i++]]=j)
 		if(rank[i]) for(j?j--:0,p=sa[rank[i]-1];str[i+j]==str[p+j];j++);
}
char temp[4050];
int main()
{
    int k,d;
    scanf("%d%s",&k,temp);
    d=strlen(temp);str[n=k]=0;
	memset(tsa,-1,sizeof(tsa));
	memset(tsb,-1,sizeof(tsb));
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<k;j++) str[j]=temp[i+j<d?i+j:i+j-d];get_sa();
        int ans=n-sa[0],now=n;
        for(int j=1;j<k;j++)
            ans+=k-sa[j]-height[j];
        printf("%d%c",ans,d-1-i?' ':10);
    }
    return 0;
}
