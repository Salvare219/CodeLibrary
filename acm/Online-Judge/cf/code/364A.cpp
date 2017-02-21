#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#include<map>
int sum[4002];
char str[4002];
int mp[500005];
int main()
{
//    freopen("2.txt","r",stdin);
    long long a,n;scanf("%I64d%s",&a,str);
    n=strlen(str);
    for(int i=0;i<n;i++)
        sum[i+1]=sum[i]+str[i]-'0';
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=n;j++)
            mp[sum[j]-sum[i]]++;
    map<int,long long>::iterator it;
    long long ans=0;
    if(a==0)
    {
        long long te=mp[0];
        for(int i=0;i<500000;i++)
        {
            long long c=i,b=mp[i];
            if(c==0) ans+=te*te;
            else ans+=2*b*te;
        }
        printf("%I64d\n",ans);
    }
    else
    {
        for(int i=0;i<500000;i++)
        {
            long long c=i,b=mp[i];
            if(c*c>a) break;
            if(c && a%c==0)
            {
                int d=a/c;
                if(d<500000 && mp[d])
                {
                    if(d!=c) ans+=2*b*mp[d];
                    else ans+=b*b;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
