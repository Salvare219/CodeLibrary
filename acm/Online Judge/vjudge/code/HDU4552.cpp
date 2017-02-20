#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sa[1000050],tsa[2000050],height[1000050];
int rank[1000050],tsb[2000050],bas[1000050];
char str[1000050];
int n;
void get_sa()
{
	int i,j,m=180,p,*x=tsa,*y=tsb;
	memset(tsa,-1,sizeof(tsa));
	memset(tsb,-1,sizeof(tsb));
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
int main()
{
    while(scanf("%s",str)==1)
    {
        n=strlen(str);get_sa();
        int ans=n,now=n;
        for(int i=rank[0]+1;i<n;i++)
            now=min(now,height[i]),ans=(ans+now)%256;
        now=n;
        for(int i=rank[0];i>0;i--)
            now=min(now,height[i]),ans=(ans+now)%256;
        printf("%d\n",ans);
    }
    return 0;
}
