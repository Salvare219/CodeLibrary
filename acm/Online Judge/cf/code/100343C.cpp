#include <bits/stdc++.h>

#define oo 1e10
using namespace std;

vector<pair<int, double> > ori[1010];
vector<int> edgevnumber[1010];
vector<pair<int, double> > edgev[1010];

int n, m;
queue<int> q;
double dist[1010];
int inque[1010];
double toprint[20010];

double caldist()
{
    for (int i=1; i<=n; i++)
        dist[i] = oo;
    dist[1] = 0;
    q.push(1);
    inque[1] = 1;
    while (!q.empty())
    {
        int cnt = q.front();
        q.pop();
        inque[cnt] = 0;
        for (int i=0; i<(int)edgev[cnt].size(); i++)
        {
            int v = edgev[cnt][i].first;
            double w = edgev[cnt][i].second;
            if (dist[cnt] + w < dist[v])
            {
                dist[v] = dist[cnt] + w;
                if (!inque[v])
                {
                    q.push(v);
                    inque[v] = 1;
                }
            }
        }
    }
    return dist[n];
}

int tohome[20010];

int check(double ans)
{
    double temp = 0.0;
    for (int i=1; i<=n; i++)
    {
        edgev[i] = ori[i];
        for (int j = 0; j < (double) ori[i].size(); j++)
        {
            if (tohome[edgevnumber[i][j]])
            {
                edgev[i][j].second = max(1.0, edgev[i][j].second - ans);
                temp += edgev[i][j].second;
            }
            else
            {
                edgev[i][j].second = edgev[i][j].second + ans;
            }
        }
    }
    /*
    for (int i=1; i<=n; i++)
        for (int j=0; j<(int)edgev[i].size(); j++)
            toprint[edgevnumber[i][j]] = edgev[i][j].second;

    for (int i=1; i<=m; i++)
        printf("%10lf%c", toprint[i], (i==m)?'\n':' ');

    printf("%lf %lf %lf\n", ans, temp, caldist()); 
    */
    return temp/2.0 <= caldist();
}


int main()
{
    freopen("lateagain.in", "r", stdin);
    freopen("lateagain.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        int u, v;
        double w;
        scanf("%d%d%lf", &u, &v, &w);
        ori[u].push_back(make_pair(v, w));
        ori[v].push_back(make_pair(u, w));
        edgevnumber[u].push_back(i);
        edgevnumber[v].push_back(i);
    }
    memset(tohome, 0, sizeof(tohome));
    scanf("%d", &tohome[0]);
    for (int i=1; i<=tohome[0]; i++)
    {
        int x;
        scanf("%d", &x);
        tohome[x] = 1;
    }
    double l = 0.0, r = 1e4; 
    for (int i=1; i<=100; i++)
    {
        double h = (l+r)/2;
        if (check(h))
            r = h;
        else
            l = h;
    }
    for (int i=1; i<=n; i++)
        for (int j=0; j<(int)edgev[i].size(); j++)
            toprint[edgevnumber[i][j]] = edgev[i][j].second;

    printf("%.10lf\n", l);
    for (int i=1; i<=m; i++)
        printf("%.10lf%c", toprint[i], (i==m)?'\n':' ');

    fclose(stdin);
    fclose(stdout);
    return 0;
}
