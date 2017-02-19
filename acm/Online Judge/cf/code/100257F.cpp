#include <bits/stdc++.h>

using namespace std;

int trip[2000];
int way[2000];
int dp[2000];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        int x, y;
        scanf("%d:%d", &x, &y);
        char str[10];
        scanf("%s", str);
        trip[i] = x*60+y;
        if (str[0] == 'S')
            way[i] = 0;
        else
            way[i] = 1;
    }
    int ans = 0;
    for (int i=1; i<=n; )
    {
        if (i!=n && trip[i+1] - trip[i] <= 90 && way[i] + way[i+1] <= 1)
        {
            int under = way[i] + way[i+1];
            ans += 44;
            int j = i+2;
            while (trip[j] -trip[i] <=90)
            {
                under += way[j];
                if (under > 1)
                    break;
                j++;
            }
            i = j;
        }
        else
        {
            if (way[i])
                ans += 28;
            else
                ans += 26;
            i++;
        }
    }

    memset(dp, 0, sizeof(dp));
    trip[0] = -1000;
    for (int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + (way[i]?28:26);
        int under = way[i];
        for (int j=i-1; j; j--)
        {
            if (trip[i] - trip[j] > 90)
                break;
            under += way[j];
            if (under > 1)
                break;
            dp[i] = min(dp[i], dp[j-1] + 44);
        }
        //cout<<trip[i]<<" "<<dp[i] <<" "<<endl;
    }
    printf("%d %d\n", ans, dp[n]);
    return 0;
}
