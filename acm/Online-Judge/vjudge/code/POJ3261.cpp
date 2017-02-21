#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sa[20050],tsa[40050],height[20050];
int rank[20050],tsb[40050],bas[20050];
int str[20050];
int n;
void get_sa()
{
	int i,j,m=n,p,*x=tsa,*y=tsb;
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
#include<map>
int main()
{
    int x,k;map<int,int>mp;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&x),str[i]=x,mp[x]=i;
    for(int i=0;i<n;i++) str[i]=mp[str[i]];
    str[n]=-1;get_sa();
    int ans=0;mp.clear();
    for(int i=1;i<k;i++)
        mp[height[i]]++;
    ans=mp.begin()->first;
    for(int i=k;i<n;i++)
    {
        mp[height[i]]++;mp[height[i-k+1]]--;
        if(mp[height[i-k+1]]==0) mp.erase(mp.find(height[i-k+1]));
        ans=max(ans,mp.begin()->first);
    }
    printf("%d\n",ans);
    return 0;
}
