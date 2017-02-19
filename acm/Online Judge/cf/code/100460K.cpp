#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > pack;

int ans1[100010], ans2[100010];

int spell1[100010], spell2[100010];

int seri1[100010], seri2[100010];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &spell1[i]);
    for (int i=1; i<=n; i++)
        scanf("%d", &spell2[i]);
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
        scanf("%d", &seri1[i]);
    for (int i=1; i<=m; i++)
        scanf("%d", &seri2[i]);

    int cnt;
    
    pack.clear();
    for (int i=1; i<=n; i++)
        pack.push_back(make_pair(spell1[i], -i));
    for (int i=1; i<=m; i++)
        pack.push_back(make_pair(seri1[i], i));
    sort(pack.begin(), pack.end(), greater<pair<int, int> >());
    cnt = n+1;
    for (int i=0; i<(int)pack.size(); i++)
    {
        if (pack[i].second < 0)
            cnt = min(cnt, -pack[i].second);
        else
            ans1[pack[i].second] = cnt;
    }

    pack.clear();
    for (int i=1; i<=n; i++)
        pack.push_back(make_pair(spell2[i], -i));
    for (int i=1; i<=m; i++)
        pack.push_back(make_pair(seri2[i], i));
    sort(pack.begin(), pack.end(), greater<pair<int, int> >());
    cnt = n+1;
    for (int i=0; i<(int)pack.size(); i++)
    {
        if (pack[i].second < 0)
            cnt = min(cnt, -pack[i].second);
        else
            ans2[pack[i].second] = cnt;
    }
    
    for (int i=1; i<=m; i++)
        if (ans1[i] > ans2[i])
            printf("Constantine\n");
        else if (ans1[i] < ans2[i])
            printf("Mike\n");
        else
            printf("Draw\n");
    return 0;

}
