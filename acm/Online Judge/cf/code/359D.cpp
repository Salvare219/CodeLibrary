#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int num[400005],n;
int dp[400005][30];
vector<int> ans,f;
int fin;
int gcd(int a,int b)
{
    int c=a%b;
    while(c)
    {
        a=b;b=c;
        c=a%b;
    }
    return b;
}
void rmq()
{
	for(int i=0;i<n;i++) dp[i][0]=num[i];
	int len=1,s=1;
	while(len<=n)
	{
		len*=2;
		for(int j=0;j<n;j++)
		{
			if(j+len>n) break;
			dp[j][s]=gcd(dp[j][s-1],dp[j+len/2][s-1]);
		}
		s++;
	}
}
int g(int l,int r)
{
    int mid=log(r-l+1.0)/log(2.0);
    int len=1<<mid;
    return gcd(dp[l][mid],dp[r-len+1][mid]);
}
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    int l,r,mid,s,a,b;
    for(int i=0;i<n;i++)
        scanf("%d",num+i);
    rmq();
    fin=0;ans.clear();
    for(int i=0;i<n;i++)
    {
        l=0,r=i;
        while(r>l)
        {
            mid=(l+r)>>1;
            if(g(mid,i)==num[i]) r=mid;
            else l=mid+1;
        }
        a=r;
        l=i,r=n-1;
        while(r>l)
        {
            mid=(l+r)/2+1;
            if(g(i,mid)==num[i]) l=mid;
            else r=mid-1;
        }
        b=l;
        if(b-a>fin)
        {
            fin=b-a;ans.clear();
            ans.push_back(a);
        }
        else if(b-a==fin) ans.push_back(a);
    }
    int las=-1;
    for(int i=0;i<ans.size();i++)
        if(las!=ans[i]) f.push_back(ans[i]+1),las=ans[i];
    printf("%d %d\n",f.size(),fin);
    for(int i=0;i<f.size();i++)
        printf("%d ",f[i]);
    putchar(10);
    return 0;
}
