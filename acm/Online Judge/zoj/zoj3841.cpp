#include <bits/stdc++.h>
using namespace std;


const int mod=1000000007;
char s[100];
int c[20];
int lib[200];
long long C[70][70];
int main()
{
    for(int i='2';i<='9';i++)
        lib[i]=i-'0';
    lib['1']=10;
    lib['A']=1;
    lib['J']=11;
    lib['Q']=12;
    lib['K']=13;
    for(int i=0;i<=60;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    while(~scanf("%s",s))
    {
        memset(c,0,sizeof(c));
        for(int i=0;s[i];i++)
        {
            c[lib[s[i]]]++;
            if(s[i]=='1')i++;
        }
        int tot=0;
        for(int i=1;i<=13;i++)
            c[i]=4-c[i],tot+=c[i];
        int x=52-tot,y=tot;
        long long ans=0;
        for(int i=0;s[i];i++)
        {
            int f=0;
            for(int j=1;j<lib[s[i]];j++)
                if(c[j]>=1)
                {
                    long long cnt=1,h=tot-1;
                    for(int z=1;z<=13;z++)
                        if(z==j)
                            cnt=cnt*C[h][c[z]-1]%mod,h-=c[z]-1;
                        else
                            cnt=cnt*C[h][c[z]]%mod,h-=c[z];
                    ans=(ans+cnt)%mod;
                }
            if(c[lib[s[i]]]==0)
                break;
            c[lib[s[i]]]--;
            tot--;
            if(s[i]=='1')i++;
        }
        if(tot==0)
        {
            if(y-tot>=x);
            else ans=(ans+1)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}