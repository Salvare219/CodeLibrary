#include <bits/stdc++.h>

using namespace std;

int grid[20][20];
int ans[20][20];
int ship[10]={0,4,3,3,2,2,2,1,1,1};
int main()
{
    freopen("battleship.in", "r", stdin);
    freopen("battleship.out", "w" , stdout);
    
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
            scanf("%d", &grid[i][j]);
    memset(ans, 0, sizeof(ans));
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
            if (grid[i][j]==100)
            {
                ans[i][j] = 1;
                for (int s = i-1; s<=i+1; s++)
                    for (int t=1; t<=10; t++)
                        if (i!=s||j!=t)
                            ans[s][t] = -1;
            }

    int placed = 1;
    for (int i=1; i<=10; i+=2)
        for (int j=1; j<=10; j++)
            if (ans[i][j] == 0 && placed<=9 && 10-j+1>=ship[placed])
            {
                for (int k=0; k<ship[placed]; k++)
                    ans[i][j+k] = 1;
                j+=ship[placed];
                placed++;
            }

    for (int i=1; i<=10; i++)
    {
        for (int j=1; j<=10; j++)
            if (ans[i][j] == 1)
                printf("#");
            else
                printf(".");
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
