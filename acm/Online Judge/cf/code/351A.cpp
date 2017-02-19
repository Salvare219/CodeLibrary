#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int num[5000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    n*=2;
    char str[40];
    int free=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        int c=0;
        for(int j=0;str[j];j++)
            if(str[j]!='.') c=c*10+str[j]-'0';
        num[i]=c%1000;
        if(num[i]) free++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=num[i];
    int tim=0;
    for(int i=0;i<free;i++)
    {
        if(ans>=1000) ans-=1000,tim++;
        if(tim==n/2) break;
    }
    if(tim==n/2) ;
    else
    {
        if(tim==free) ;
        else
        {
            int res=n-free;
            if(n/2-tim<=res) ans=min(ans,1000-ans);
            else ans-=(n/2-tim-res)*1000;
        }
    }
    ans=abs(ans);
    int fa=ans/1000,f=ans%1000;
    printf("%d.%03d\n",fa,f);
    return 0;
}
