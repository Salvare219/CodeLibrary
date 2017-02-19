#include<bits/stdc++.h>
using namespace std;


char s[50050][9];
map<string,int>mp;
long long dp[1<<6];
void utf(long long a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    for(int i=0;i<len;i++)
        a[l+i]-=a[mid+i];
    utf(a,l,mid);utf(a,mid,r);
}
int pos[555];
long long ans[555];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("high.in","r",stdin);
    freopen("high.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    int lim=1<<5;
    for(int i=0;i<lim;i++)
    {
        int k=0;mp.clear();
        for(int j=0;j<5;j++)
            if((1<<j)&i)
                pos[k++]=j;
        char te[7];
        string c;
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            for(int z=0;z<k;z++)
                te[z]=s[j][pos[z]];
            te[k]=0;
            c=te;
            long long h=mp[c];
            sum-=h*(h-1)/2;
            sum+=h*(h+1)/2;
            mp[c]++;
        }
        dp[i]=sum;
    }
    //for(int i=0;i<(1<<5);i++)
    //    printf("%d %d\n",i,dp[i]);
    utf(dp,0,1<<5);
    //for(int i=0;i<(1<<5);i++)
    //    printf("%d %d\n",i,dp[i]);
    for(int i=0;i<(1<<5);i++)
    {
        int k=0;
        for(int j=0;j<5;j++)
            if((1<<j)&i)
                k++;
        ans[k]+=dp[i];
    }
    for(int i=5;i>-1;i--)
        printf("%I64d ",ans[i]);
    return 0;
}
