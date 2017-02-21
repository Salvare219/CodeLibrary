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
int stack[200050][3];
int main()
{
    int m;
    while(scanf("%d",&m) && m)
    {
        scanf("%s",str);int d=strlen(str);
        str[d]='%';scanf("%s",str+d+1);
        n=strlen(str);get_sa();
        long long ans=0,h1=0,h2=0;
        int k=0;
        for(int i=2;i<=n;i++)
        {
            if(sa[i-1]>d) ans+=h1;
            else ans+=h2;
            if(height[i]>=m)
            {
                int sum1=(sa[i-1]<d),sum2=(sa[i-1]>d);
                while(k && stack[k-1][0]>=height[i]-m+1)
                {
                    k--;sum1+=stack[k][1];sum2+=stack[k][2];
                    h1-=stack[k][0]*stack[k][1];
                    h2-=stack[k][0]*stack[k][2];
                }
                stack[k][1]=sum1;stack[k][2]=sum2;
                stack[k++][0]=height[i]-m+1;
                h1+=sum1*(height[i]-m+1);
                h2+=sum2*(height[i]-m+1);
            }
            else h1=h2=k=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
