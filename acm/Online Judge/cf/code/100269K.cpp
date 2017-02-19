#include <bits/stdc++.h>

using namespace std;

int gg, gb, bg, bb;

bool check(int x, int y)
{
    if (x < gg+1)
        return 0;
    if (y < bb+1)
        return 0;
    if (x < bg)
        return 0;
    if (y < bb)
        return 0;
    if (x*gg % 2)
        return 0;
    if (y*bb % 2)
        return 0;
    return x*gb == y * bg;
}

vector<pair<int, int> > ans;
vector<pair<int, int> > degree;

int main()
{
    freopen("kids.in", "r", stdin);
    freopen("kids.out", "w" ,stdout);
    scanf("%d%d%d%d", &gg, &gb, &bg, &bb);

    for (int tot = 1; tot; tot++)
        for (int girls = 1; girls <= tot; girls ++)
            if (check(girls, tot - girls))
            {
                int boys = tot - girls;
                ans.clear();

                degree.clear();
                for (int i=1; i<=girls; i++)
                    degree.push_back(make_pair(0, i));
                while  ((int)degree.size()>0)
                {
                    sort(degree.begin(), degree.end());
                    for (int i=1; i<=(int)gg - degree[0].first; i++)
                    {
                        ans.push_back(make_pair(degree[0].second, degree[i].second));
                        degree[i].first++;
                    }
                    degree.erase(degree.begin());
                }

                degree.clear();
                for (int i=1; i<=boys; i++)
                    degree.push_back(make_pair(0, girls + i));
                while  ((int)degree.size()>0)
                {
                    sort(degree.begin(), degree.end());
                    for (int i=1; i<= bb - degree[0].first; i++)
                    {
                        ans.push_back(make_pair(degree[0].second, degree[i].second));
                        degree[i].first++;
                    }
                    degree.erase(degree.begin());
                }
                //printf("%d\n", ans.size());

                degree.clear();
                for (int i=1; i<=boys; i++)
                    degree.push_back(make_pair(0, girls + i));
                for (int i=1; i<=girls; i++)
                {
                    sort(degree.begin(), degree.end());
                    for (int j=0; j<gb; j++)
                    {
                        ans.push_back(make_pair(i, degree[j].second));
                        degree[j].first ++;
                    }
                }
                
                printf("%d %d\n", girls, boys);
                for (int i=0; i<(int)ans.size(); i++)
                    printf("%d %d\n", ans[i].first, ans[i].second);
                fclose(stdin);
                fclose(stdout);
                return 0;
            }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
