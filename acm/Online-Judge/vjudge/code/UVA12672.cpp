#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int mod=1000000007;
long long dp[105][105][12];
long long C[200][200];
char s[200];
int cnt[20];
int main()
{
    for(int i=0;i<120;i++)C[i][0]=1;
    for(int i=1;i<120;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    while(scanf("%s",s)==1)
    {
        memset(cnt,0,sizeof(cnt));
        memset(dp,0,sizeof(dp));
        int a=0,b=0,len=0;
        for(;s[len];len++)
            cnt[s[len]-'0']++,len%2?b++:a++;
        if(len%2)a--;
        else b--;
        for(int i=0;i<=min(a,cnt[0]);i++)
            dp[i][cnt[0]-i][0]=C[a][i]*C[b][cnt[0]-i]%mod;
        if(len%2)a++;
        else b++;
        len=cnt[0];
        for(int i=1;i<10;i++)
            if(cnt[i])
            {
                for(int j=0;j<=a&&len-j>=0;j++)
                    for(int k=max(0,len-j+cnt[i]-b);j+k<=a&&k<=cnt[i];k++)
                    {
                        int sa=(i*k+i*(cnt[i]-k)*10)%11;
                        for(int r=0;r<11;r++)
                            dp[j+k][len-j+cnt[i]-k][(r+sa)%11]=(dp[j+k][len-j+cnt[i]-k][(r+sa)%11]+((dp[j][len-j][r]*C[a-j][k])%mod*C[b-len+j][cnt[i]-k])%mod)%mod;
                    }
                len+=cnt[i];
            }
        printf("%lld\n",dp[a][b][0]);
    }
	return 0;
}
