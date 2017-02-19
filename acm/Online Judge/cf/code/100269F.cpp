#include <bits/stdc++.h>

using namespace std;

int appear[1010];

int diff[1010][1010];
int pass[1010];

int dp[1010][50];

int main()
{
    freopen("flight.in", "r", stdin);
    freopen("flight.out", "w", stdout);

    int n, m, part;
    scanf("%d%d%d", &n, &m, &part);
    for (int i=1; i<=n; i++)
        scanf("%d", &pass[i]);
    memset(appear, 0, sizeof(appear));
    memset(diff, 0, sizeof(diff));
    for (int i=1; i<=n; i++)
    {
        appear[pass[i]]++;
        int temp = 0;
        for (int j=pass[i]-1; j; j--)
        {
            temp += appear[j];
            //cout<<pass[i]<<" "<<j<<" "<<temp<<endl;
            diff[j][pass[i]] += temp;
        }
    }
    for (int i=1; i<=m; i++)
        for (int j=i; j<=m; j++)
            diff[i][j] += diff[i][j-1];
    //cout<<"--------------------------------"<<endl;
    /*
    for (int i=1; i<=m; i++)
        for (int j=i; j<=m; j++)
            cout<<i<<" "<<j<<" "<<diff[i][j]<<endl;
            */

    memset(dp, 0, sizeof(dp));
    for (int i=m; i; i--)
    {
        dp[i][1] = diff[i][m];
        for (int j=2; j<=part; j++)
        {
            dp[i][j] = dp[i][1];
            for (int k = i; k<=m; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k+1][j-1] + diff[i][k]);
            }
        }
    }
    cout<<dp[1][part]<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
