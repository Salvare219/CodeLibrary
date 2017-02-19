#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
long long C[1050][1050];
int main()
{
    //freopen("1.txt","r",stdin);
    int k;scanf("%d",&k);
    long long ans=1,las=0;
    C[0][0]=1;
    for(int i=1;i<=1005;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    for(int i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        las+=x-1;
        ans=ans*C[las][x-1]%mod;
        las++;
    }
    printf("%d\n",(int)ans);
    return 0;
}

