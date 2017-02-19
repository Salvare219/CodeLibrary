#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
char s[1000050];
const unsigned long long sd=13131;
long long s1[1000050],pw[1000050];
unsigned long long s2[1000050],pw2[1000050];
int len;
long long cal(int l,int r)
{
    return ((s1[r+1]-s1[l])*pw[len-r-1]%mod+mod)%mod;
}
unsigned long long cal2(int l,int r)
{
    return (s2[r+1]-s2[l])*pw2[len-r-1];
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d%s",&n,&m,s);
    len=strlen(s);pw[0]=pw2[0]=1;
    for(int i=1;i<=len;i++)
    {
        s1[i]=(s1[i-1]+pw[i-1]*s[i-1])%mod;
        s2[i]=(s2[i-1]+pw2[i-1]*s[i-1]);
        pw[i]=pw[i-1]*sd%mod;
        pw2[i]=pw2[i-1]*sd;
    }
    int las=-1,x;
    int ans=0,h=1;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        x--;
        if(x>las)
            ans+=x-las-1;
        else
        {
            if(cal(0,las-x)==cal(len-las+x-1,len-1)&&cal2(0,las-x)==cal2(len-las+x-1,len-1));
            else h=0;
        }
        las=x+len-1;
    }
    ans+=max(0,n-las-1);
    if(h==0)
        puts("0");
    else
    {
        long long sum=1;
        for(int i=0;i<ans;i++)
            sum=sum*26%mod;
        printf("%d\n",(int)sum);
    }
    return 0;
}
