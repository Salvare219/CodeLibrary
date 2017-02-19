#include <bits/stdc++.h>

using namespace std;


vector<pair<int, int> > rider[100010];

int event[100010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
        rider[i].clear();
    for (int i=1; i<=n; i++)
    {
        int  w;
        scanf("%d%d", &event[i], &w);
        for (int j=1; j<=event[i]; j++)
        {
            int x;
            scanf("%d", &x);
            rider[x].push_back(make_pair(w, i));
        }
    }
    for (int i=1; i<=m; i++)
    {
        if (rider[i].size() > 0)
        {
            sort(rider[i].begin(), rider[i].end());
            for (int j=1; j<(int)rider[i].size(); j++)
                if (rider[i][j].first > rider[i][0].first)
                    event[rider[i][j].second] --;
        }
    }
    int flag = 1;
    for (int i = 1; i<=n; i++)
        if (event[i] == 0)
            flag = 0;
    if (flag)
    {
        printf("Good memory\n");
        for (int i=1; i<=m; i++)
        {
            if (rider[i].size() > 0)
                printf("%d", rider[i][0].first);
            else
                printf("1");
            if (i==m)
                printf("\n");
            else
                printf(" ");
        }
    }
    else
    {
        printf("Poor memory\n");
    }
}
