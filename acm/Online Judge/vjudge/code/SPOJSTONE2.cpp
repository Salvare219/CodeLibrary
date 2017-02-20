#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;


#define INFINITE 0x3f3f3f3f
#define MAX(a,b)((a)>(b)?(a):(b))
#define MIN(a,b)((a)<(b)?(a):(b))
#define MAXK 110
#define MAXN 10010
#define Mod 1000000007




using namespace std;

int K , N ;
int c[MAXK] ;
long long dp[MAXK][MAXN] ;
long long C[MAXN][MAXK] ;



void pri_get_C()
{
      memset(C,0,sizeof(C));
      C[0][0] = 1 ;
      for (int i = 1 ; i <= 10000 ; i++)
      {
            C[i][0] = 1 ;
            for (int j = 1 ; j <= MIN(100,i) ; j++)
            {
                  C[i][j] = (long long)(C[i-1][j-1] + C[i-1][j]) % Mod ;
            }
      }
}

int main()
{
      //freopen("input.txt","r",stdin);
      //freopen("ouput.txt","w",stdout);
      int pos = 0;
      pri_get_C();
      while (scanf("%d",&K) != EOF)
      {
            pos++ ;
            for (int i  = 1 ; i <= K ; i++ ) scanf("%d",&c[i]);
            int N = 0 ;
            memset(dp,0,sizeof(dp));
            dp[0][0] = 1 ;
            for (int k = 1 ; k <= K ; k++)
            {
                  N += c[k] ;
                  for (int i = 0 ; i <= N; i++)
                        for (int j = 0 ; j <= MIN(c[k],i) ; j++)
                        {
                              dp[k][i] += (long long)dp[k-1][i-j] * C[i][j] % Mod;
                              dp[k][i] %= Mod ;
                        }
                  //for (int i = 0 ; i <= N; i++)
                  //      printf("dp[%d][%d] = %I64d\n",k,i,dp[k][i]);
            }
            long long ans = 0 ;
            for (int i = 1 ; i <= N ; i++)
            {
                  ans += dp[K][i] ;
                  if (ans > Mod) ans %= Mod ;
            }
            printf("Case %d: %lld\n",pos,ans);
      }
      return 0 ;
}
