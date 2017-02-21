#include <bits/stdc++.h>

using namespace std;

int n, m, q;

long long grid[110][110];

char str[10];

long long theque[200];

long long score;

void goleft()
{
    for (int i=1; i<=n; i++)
    {
        theque[0] = 0;
        for (int j=1; j<=n; j++)
        {
            if (grid[i][j] != -1)
            {
                theque[0]++;
                theque[theque[0]] = grid[i][j];
            }
            grid[i][j] = -1;
        }
        for (int j=1, pos = 1; j<=theque[0]; j++, pos++)
        {
            if (j<theque[0] && theque[j] == theque[j+1])
            {
                score += 2*theque[j];
                grid[i][pos] = 2 * theque[j];
                j++;
            }
            else
            {
                grid[i][pos] = theque[j];
            }
        }
    }
}

void goright()
{
    for (int i=1; i<=n; i++)
    {
        theque[0] = 0;
        for (int j=n; j; j--)
        {
            if (grid[i][j] != -1)
            {
                theque[0]++;
                theque[theque[0]] = grid[i][j];
            }
            grid[i][j] = -1;
        }
        for (int j=1, pos = n; j<=theque[0]; j++, pos--)
        {
            if (j<theque[0] && theque[j] == theque[j+1])
            {
                score += 2*theque[j];
                grid[i][pos] = 2 * theque[j];
                j++;
            }
            else
            {
                grid[i][pos] = theque[j];
            }
        }
    }
}

void goup()
{
    for (int i=1; i<=n; i++)
    {
        theque[0] = 0;
        for (int j=1; j<=n; j++)
        {
            if (grid[j][i] != -1)
            {
                theque[0]++;
                theque[theque[0]] = grid[j][i];
            }
            grid[j][i] = -1;
        }
        for (int j=1, pos = 1; j<=theque[0]; j++, pos++)
        {
            if (j<theque[0] && theque[j] == theque[j+1])
            {
                score += 2*theque[j];
                grid[pos][i] = 2 * theque[j];
                j++;
            }
            else
            {
                grid[pos][i] = theque[j];
            }
        }
    }
}

void godown()
{
    for (int i=1; i<=n; i++)
    {
        theque[0] = 0;
        for (int j=n; j; j--)
        {
            if (grid[j][i] != -1)
            {
                theque[0]++;
                theque[theque[0]] = grid[j][i];
            }
            grid[j][i] = -1;
        }
        for (int j=1, pos = n; j<=theque[0]; j++, pos--)
        {
            if (j<theque[0] && theque[j] == theque[j+1])
            {
                score += 2*theque[j];
                grid[pos][i] = 2 * theque[j];
                j++;
            }
            else
            {
                grid[pos][i] = theque[j];
            }
        }
    }
}

int main()
{
    //freopen("1.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    memset(grid, -1, sizeof(grid));
    for (int i=1; i<=m; i++)
    {
        long long v;
        int x, y;
        scanf("%I64d%d%d", &v, &x, &y);
        grid[x][y] = v;
    }
    scanf("%d", &q);
    score = 0;
    for (int i=1; i<=q; i++)
    {
        scanf("%s", str);
        long long v;
        int x, y;
        scanf("%I64d%d%d", &v, &x, &y);
        if (str[0] == 'L')
        {
            goleft();
        }
        else if (str[0] == 'R')
        {
            goright();
        }
        else if (str[0] == 'U')
        {
            goup();
        }
        else if (str[0] == 'D')
        {
            godown();
        }
        grid[x][y] = v;
    }
    cout<<score;
    //printf("%d\n", score);
    return 0;
}
