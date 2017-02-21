#include <bits/stdc++.h>

#define oo (1LL<<29)
using namespace std;

int cost[4];

char stra[4000];
char strb[4000];

int dp[3010][3010];
int from[3010][3010][2];
int mini[3010];
int n, m;

vector<pair<int, int> > todelete;
int ansscore;
int anslen;
char ansstr[10010];

int main()
{
    //cout<<oo<<endl;
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    for (int i=0; i<4; i++)
        scanf("%d", &cost[i]);
    scanf("%s%s", stra, strb);
    n = strlen(stra);
    m = strlen(strb);
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = oo;
    memset(from, 0, sizeof(from));

    dp[0][0] = 0;
    for (int j=0; j<m; j++)
        mini[j] = 0;
        
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
        {
            if (dp[mini[j]][j] + cost[0] < dp[i][j])
            {
                dp[i][j] = dp[mini[j]][j] + cost[0];
                from[i][j][0] = 0;
                from[i][j][1] = mini[j];
            }
            if (dp[i][j] < dp[mini[j]][j])
                mini[j] = i;

            if (j!=m && dp[i][j] + cost[1] < dp[i][j+1])
            {
                dp[i][j+1] = dp[i][j] + cost[1];
                from[i][j+1][0] = 1;
            }
            if (i!=n && dp[i][j] + cost[2] < dp[i+1][j])
            {
                dp[i+1][j] = dp[i][j] + cost[2];
                from[i+1][j][0] = 2;
            }
            if (i!=n && j!=m && stra[i] == strb[j] && dp[i][j] + cost[3] < dp[i+1][j+1])
            {
                dp[i+1][j+1] = dp[i][j] + cost[3];
                from[i+1][j+1][0] = 3;
            }
        }

    todelete.clear();
    ansscore = 0;
    anslen = 0;

    /*
    int ansn = n;
    for (int i = 0; i<=n; i++)
        if (dp[i][m] < dp[ansn][m])
            ansn = i;
            */
    ansscore = dp[n][m];
    for (int s = n, t = m; s !=0 || t != 0; )
    {
        if (from[s][t][0] == 0)
        {
            todelete.push_back(make_pair(from[s][t][1] + 1, s));
            s = from[s][t][1];
        }
        else
        {
            anslen++;
            if (from[s][t][0] == 1)
            {
                ansstr[anslen] = 'I';
                t = t - 1;
            }
            else if (from[s][t][0] == 2)
            {
                ansstr[anslen] = 'D';
                s = s - 1;
            }
            else if (from[s][t][0] == 3)
            {
                ansstr[anslen] = 'C';
                s = s - 1;
                t = t - 1;
            }
        }
    }
    printf("%d\n", ansscore);

    sort(todelete.begin(), todelete.end());
    printf("%d\n", (int)todelete.size());
    for (int i=0; i<(int)todelete.size(); i++)
        printf("%d %d\n", todelete[i].first, todelete[i].second);
    for (int i=anslen; i; i--)
        printf("%c", ansstr[i]);
    printf("\n");

    fclose(stdin);
    fclose(stdout);
    return 0;
}
