#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> dict;
map<pair<int, int>, int> sold;

int main()
{
    freopen("bricks.in","r",stdin);
    freopen("bricks.out","w",stdout);

    int n,m;
    scanf("%d%d", &n, &m);
    dict.clear();
    sold.clear();
    int ans = 0;
    for (int i=1; i<=m&&!ans; i++)
    {
        int s, t;
        scanf("%d%d",&s, &t);
        sold[make_pair(s,t)] = 1;
        int x = s-1, y = t-1;
        if (x>=y)
        {
            dict[make_pair(x, y)] ++;
            if(dict[make_pair(x, y)]==2&&!sold[make_pair(x,y)])
                ans = i;
        }
        x = s-1, y = t;
        if (x>=y)
        {
            dict[make_pair(x, y)] ++;
            if(dict[make_pair(x, y)]==2&&!sold[make_pair(x,y)])
                ans = i;
        }
    }
    if(ans==0)
        ans = -1;
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
