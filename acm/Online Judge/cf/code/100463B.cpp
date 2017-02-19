#include <bits/stdc++.h>

using namespace std;

int n;

map<string, int> dict;

int appear[40000];

int edgev[40000][3];

vector< pair<int, int> > songs[40000];

int tot;

int treetype[40000];
int nametype[40000];
int common[40000];

int calcommon(int cnt)
{
    if (songs[cnt].size()<=1)
        common[cnt] = 0;
    else
    {
        int u = songs[cnt][0].first;
        int flag = 1;
        for (int i=1; i<(int)songs[cnt].size(); i++)
            if (songs[cnt][i].first != u && songs[cnt][i].second != u )
            {
                flag = 0;
                break;
            }
        if (!flag)
        {
            u = songs[cnt][0].second;
            flag = 1;
            for (int i=1; i<(int)songs[cnt].size(); i++)
                if (songs[cnt][i].first != u && songs[cnt][i].second != u )
                {
                    flag = 0;
                    break;
                }
        }
        if (flag)
            common[cnt] = u;
        else
            common[cnt] = -1;
    }
    return common[cnt];
}

int main()
{
    int CAS = 0;
    while (scanf("%d", &n)==1)
    {
        if (n==0)
            break;
        CAS++;
        memset(appear, 0, sizeof(appear));
        memset(nametype, 0, sizeof(nametype));
        memset(treetype, 0, sizeof(treetype));
        memset(common, 0, sizeof(common));
        dict.clear();

        tot = 0;
        for (int i=1; i<=n; i++)
        {
            char str1[30], str2[30], str3[30];
            scanf("%s%s%s", str1, str2, str3);
            string a(str1), b(str2), c(str3);
            if (dict.find(a) == dict.end())
            {
                dict[a] = dict.size();
                tot++;
            }
            if (dict.find(b) == dict.end())
            {
                dict[b] = dict.size();
                tot++;
            }
            if (dict.find(c) == dict.end())
            {
                dict[c] = dict.size();
                tot++;
            }
            int na = dict[a], nb = dict[b] , nc = dict[c];
            appear[na] ++;
            appear[nb] ++;
            appear[nc] ++;
            edgev[i][0] = na;
            edgev[i][1] = nb;
            edgev[i][2] = nc;
        }

        for (int i=1; i<=tot; i++)
            songs[i].clear();

        for (int i=1; i<=n; i++)
            if (appear[edgev[i][0]] == 1 && appear[edgev[i][1]] == 1&&appear[edgev[i][2]] == 1)
            {
                treetype[edgev[i][0]] = treetype[edgev[i][1]] = treetype[edgev[i][2]] = 3;
            }
            else
            {
                songs[edgev[i][0]].push_back(make_pair(edgev[i][1], edgev[i][2]));
                songs[edgev[i][1]].push_back(make_pair(edgev[i][0], edgev[i][2]));
                songs[edgev[i][2]].push_back(make_pair(edgev[i][1], edgev[i][0]));
            }

        for (int i=1; i<=tot; i++)
            calcommon(i);
        for (int i=1; i<=tot; i++)
            if (common[i] == -1)
            {
                treetype[i] = 1;
                nametype[i] = 1;
                for (int j=0; j<(int)songs[i].size(); j++)
                {
                    int u = songs[i][j].first, v = songs[i][j].second;
                    if (songs[u].size()!=1)
                    {
                        treetype[u] = 1;
                        nametype[u] = 2;
                        treetype[v] = 1;
                        nametype[v] = 3;
                    }
                    else if (songs[v].size()!=1)
                    {
                        treetype[v] = 1;
                        nametype[v] = 2;
                        treetype[u] = 1;
                        nametype[u] = 3;
                    }
                    else
                    {
                        treetype[v] = 1;
                        nametype[v] = 4;
                        treetype[u] = 1;
                        nametype[u] = 4;
                    }
                }
            }
            else if (common[common[i]] == i)
            {
                treetype[i] = 2;
                nametype[i] = 1;
                for (int j=0; j<(int)songs[i].size(); j++)
                {
                    int u = songs[i][j].first;
                    if (u == common[i])
                        u = songs[i][j].second;
                    treetype[u] = 2;
                    nametype[u] = 2;
                }
            }

        /*
        for (int i=1; i<=tot; i++)
            printf("%d %d\n", treetype[i], nametype[i]);
            */
        int ans1=0, ans2=0, ans3=0;
        for (int i=1; i<=tot; i++)
            if (treetype[i] == 3)
                ans1++, ans2++, ans3++;
            else if (treetype[i] == 2 && nametype[i] == 1)
                ans1++, ans2++;
            else if (treetype[i] == 2 && nametype[i] == 2)
                ans3++;
            else if (treetype[i] == 1 && nametype[i] == 1)
                ans1++;
            else if (treetype[i] == 1 && nametype[i] == 2)
                ans2++;
            else if (treetype[i] == 1 && nametype[i] == 3)
                ans3++;
            else if (treetype[i] == 1 && nametype[i] == 4)
                ans2++, ans3++;
        printf("Case %d: %d %d %d\n", CAS, ans1, ans2, ans3);
    }
    return 0;
}
