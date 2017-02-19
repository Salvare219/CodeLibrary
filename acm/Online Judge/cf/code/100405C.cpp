#include <bits/stdc++.h>

using namespace std;

int n, m;
char cards[100];
int pos[2000];
double dp[2000];
int main()
{
    while (scanf("%d%d", &n, &m)==2)
    {
        memset(pos, 0, sizeof(pos));
        memset(dp, 0, sizeof(dp));
        int cnt = m; 
        for (int i=1; i<=n; i++)
        {
            scanf("%s", cards);
            //puts(cards);
            int key = 0;
            if (cards[0]>='2'&&cards[0]<='9')
                key = cards[0]-'0';
            else
            {
                if (cards[0]=='1'||cards[0]=='J'||cards[0]=='Q'||cards[0]=='K')
                    key = 10;
                else if (cards[0] == 'A')
                    key = 11;
            }
            pos[cnt] = key;
            if( i!=n)
                cnt += key;
        }

            //printf("%d\n", cnt);
        for (int i=1; i<=10; i++)
            dp[i] = 0.1;
        for (int i=1; i<=cnt; i++)
            if (pos[i])
            {
                dp[i+pos[i]] += dp[i];
            }
            else
            {
                for (int k = 2; k<=9; k++)
                    dp[i+k] += dp[i]/13;
                dp[i+10]+=dp[i]*4/13;
                dp[i+11]+=dp[i]/13;
            }
        printf("%.10f\n", dp[cnt]);
    }
    return 0;
}
