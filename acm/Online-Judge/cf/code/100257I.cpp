#include <bits/stdc++.h>

using namespace std;

int have[210][10010];
vector<int> appear[210];
vector<int> common[210][210];
vector<int> temp;

int main()
{
    memset(have, 0, sizeof(have));
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n*(n-1)/2; i++)
    {
        int a, b;
        int n;
        scanf("%d%d%d", &a, &b, &n);
        for (int i=1; i<=n; i++)
        {
            int x;
            scanf("%d", &x);
            have[a][x] = 1;
            have[b][x] = 1;
            common[a][b].push_back(x);
            common[b][a].push_back(x);
        }
        sort(common[a][b].begin(), common[a][b].end());
        sort(common[b][a].begin(), common[b][a].end());
    }
    int flag = 1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=10000; j++)
            if (have[i][j])
                appear[i].push_back(j);
        for (int j=i+1; j<=n; j++)
        {
            temp.clear();
            for (int k=0; k<(int)appear[i].size(); k++)
                if (have[j][appear[i][k]])
                    temp.push_back(appear[i][k]);
           if (temp!=common[i][j])
              flag = 0; 
        }
    }
    if (flag)
    {
        puts("Yes");
        for (int i=1; i<=n; i++)
        {
            printf("%d", (int)appear[i].size());
            for (int j=0; j<(int)appear[i].size(); j++)
                printf(" %d", appear[i][j]);
            printf("\n");
        }
    }
    else
        puts("No");
    return 0;
}
