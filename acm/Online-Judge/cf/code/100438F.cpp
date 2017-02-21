#include<bits/stdc++.h>
#define len 20100
using namespace std;
vector<int> edgev[len];
int color[len];
int match[len];

int n,m;

int find(int current)
{
    int i,j;
    for (i=0;i<(int)edgev[current].size();i++)
        if (!color[j=edgev[current][i]]&& match[edgev[current][i]]!=current)
        {
            color[j]=1;
            if (!match[j]||find(match[j]))
            {
                match[j]=current;
                return 1;
            }
        }
    return 0;
}

int X, Y;

int wentr[200][200];
int wentc[200][200];
char str[200][200];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS = 1; CAS<= CAS1; CAS++)
    {
        //puts("FUCK");
        scanf("%d%d", &X, &Y);
        /*
        for (int i=1; i<=X; i++)
            scanf("%s", str[i] + 1);
            */
        //puts("FUCK");
        memset(str, 0, sizeof(str));
        for (int i=1; i<=X; i++)
            for (int j=1; j<=Y; j++)
                str[i][j] = '.';
        int p;
        scanf("%d", &p);
        for (int i=1; i<=p; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            str[s][t] = '*';
        }
        //puts("FUCK");

        scanf("%d", &p);
        for (int i=1; i<=p; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            str[s][t] = '#';
        }
        //puts("FUCK");

        n = 0;
        memset(wentr, 0, sizeof(wentr));
        memset(wentc, 0, sizeof(wentc));
        for (int i=1; i<=X; i++)
            for (int j=1; j<=Y; j++)
                if ((str[i][j] == '.' || str[i][j] == '*') && !wentr[i][j])
                {
                    n++;
                    int s = i;
                    int t = j;
                    while (str[s][t] == '.' || str[s][t] == '*')
                    {
                        wentr[s][t] = n;
                        t++;
                    }
                }
        m = n;

        for (int i=1; i<=X; i++)
            for (int j=1; j<=Y; j++)
                if ((str[i][j] == '.' || str[i][j] == '*') && !wentc[i][j])
                {
                    n++;
                    int s = i;
                    int t = j;
                    while (str[s][t] == '.' || str[s][t] == '*')
                    {
                        wentc[s][t] = n;
                        s++;
                    }
                }
        /*
        for (int i=1; i<=X; i++)
        {
            for (int j=1; j<=Y; j++)
                printf("%c", str[i][j]);
            printf("\n");
        }
        for (int i=1; i<=X; i++)
        {
            for (int j=1; j<=Y; j++)
                printf("%3d", wentr[i][j]);
            printf("\n");
        }
        for (int i=1; i<=X; i++)
        {
            for (int j=1; j<=Y; j++)
                printf("%3d", wentc[i][j]);
            printf("\n");
        }
        */

        for (int i=1; i<=n; i++)
            edgev[i].clear();
        for (int i=1; i<=X; i++)
            for (int j=1; j<=Y; j++)
                if (str[i][j] == '*')
                {
                    edgev[wentr[i][j]].push_back(wentc[i][j]);
                    //edgev[wentc[i][j]].push_back(wentr[i][j]);
                }

        /*
        for (int i=1; i<=m; i++)
        {
            printf("%d: ", i);
            for (int j=0; j<(int)edgev[i].size(); j++)
                printf("%d ", edgev[i][j]);
            printf("\n");
        }
        */

        int ans = 0;
        for (int i=1; i<=n; i++)
            match[i] = 0;
        for (int i=1; i<=m; i++)
        {
            for (int i=1; i<=n; i++) color[i] = 0;
            int temp = find(i);
            if (temp)
                ans++;
            //printf("%d\n", temp);
        }

        /*
        for (int i=1; i<=n; i++)
            printf("%d ", match[i]);
        printf("\n");
        */

        printf("%d\n", ans);
    }

    /*
    scanf("%d%d",&n,&m);
    int i,j,k;
    int ans;
    for (i=1;i<=2*n;i++)
        list[i][0]=0;
    for (i=1;i<=m;i++)
    {
        scanf("%d%d",&j,&k);
        list[j][++list[j][0]]=k+n;
        list[k+n][++list[k+n][0]]=j;
    }
    ans=0;
    for (i=1;i<=n;i++)
        match[i]=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=2*n;j++) color[j]=0;
        if (find(i))
            ans++;
    }
    printf("%d\n",ans);
    */
/*
    fclose(stdin);
    fclose(stdout);
*/
    return 0;
}
