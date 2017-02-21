#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#pragma comment(linker,"/STACK:102400000,102400000")

#define mod 1000003

using namespace std;

long long inv[1000100];
void calInv(int n)
{
    inv[0]=0; inv[1]=1;
    for (int i=2; i<=n; i++)
    {
        inv[i]=(-mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
    }
}

int n, m;
int wei[100010];
long long premul[100010];
int theresult[100010];
vector<int> edgev[100010];
set<pair<int, int> > dict[100010];
int dictsize;
pair<int, int> ans;

int dfs(int cnt, int father)
{
    premul[cnt] = (long long)premul[father] * wei[cnt] % mod;
    for (int i = 0; i<(int)edgev[cnt].size(); i++)
    {
        int v = edgev[cnt][i];
        if (v != father)
            dfs(v, cnt);
    }
    int theset = -1;
    for (int i = 0; i<(int)edgev[cnt].size(); i++)
    {
        int v = edgev[cnt][i];
        if (v != father)
        {
            if (theset == -1 || dict[theresult[v]].size() > dict[theset].size())
                theset = theresult[v];
        }
    }
    for (int i = 0; i<(int)edgev[cnt].size(); i++)
    {
        int v = edgev[cnt][i];
        if (v != father && theresult[v] != theset)
        {
            for (set<pair<int, int> >::iterator ite = dict[theresult[v]].begin(); ite != dict[theresult[v]].end(); ite++)
            {
                long long val = (long long)inv[ite->first] * premul[father] % mod * premul[cnt] % mod * m % mod;
                set<pair<int, int> >::iterator ite1 = dict[theset].lower_bound(make_pair(val, -1));
                if (ite1!=dict[theset].end()&&ite1->first == val)
                {
                    pair<int, int> temp;
                    temp.first = min(ite->second, ite1->second);
                    temp.second = max(ite->second, ite1->second);
                    ans = min(ans, temp);
                }
            }
            for (set<pair<int, int> >::iterator ite = dict[theresult[v]].begin(); ite != dict[theresult[v]].end(); ite++)
                dict[theset].insert(*ite);
            dict[theresult[v]].clear();
        }
    }
    if (theset == -1)
    {
        theset = ++dictsize;
        dict[theset].insert(make_pair(premul[cnt], cnt));
    }
    else
    {
        long long val = (long long)inv[premul[cnt]] * premul[father] % mod * premul[cnt] % mod * m % mod;
        set<pair<int, int> >::iterator ite1 = dict[theset].lower_bound(make_pair(val, -1));
        if (ite1!=dict[theset].end()&&ite1->first == val)
        {
            pair<int, int> temp;
            temp.first = min(cnt, ite1->second);
            temp.second = max(cnt, ite1->second);
            ans = min(ans, temp);
        }
        dict[theset].insert(make_pair(premul[cnt], cnt));
    }
    /*
    printf("%d:\n", cnt);
    for (set<pair<int, int> >::iterator ite = dict[theset].begin(); ite!=dict[theset].end(); ite++)
        printf("%d %d\n", ite->first, ite->second);
        */
    return theresult[cnt] = theset;
}

int main()
{
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    calInv(mod);
    while(scanf("%d%d", &n, &m) == 2)
    {
        for (int i=1; i<=n; i++)
            scanf("%d", &wei[i]);
        for (int i=1; i<n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edgev[u].push_back(v);
            edgev[v].push_back(u);
        }
        dictsize = 0;
        premul[0] = 1;
        ans = make_pair(n+1, n+1);
        dfs(1, 0);
        if (ans.first != n+1)
        {
            printf("%d %d\n", ans.first, ans.second);
        }
        else
        {
            printf("No solution\n");
        }

        for (int i=1; i<=dictsize; i++)
            dict[i].clear();
        for (int i=1; i<=n; i++)
            edgev[i].clear();
        //printf("---------------------\n");
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
