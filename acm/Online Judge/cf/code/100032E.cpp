#include <bits/stdc++.h>

using namespace std;

int ini[20000];
int aim[20000];
int d[20000];
int totabs[20000];
int totm = 0;
int cntabs[20000];
int cntrep[20000];
int ans[20000];

int main()
{
    freopen("changes.in","r",stdin);
    freopen("changes.out","w",stdout);

    int n;
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
        scanf("%d", &ini[i]);
    for (int i=1; i<=n; i++)
        scanf("%d", &aim[i]);
    for (int i=1; i<=n; i++)
        d[i] = aim[i] - ini[i];

    int solutionExist = 1;
    int totd = 0;
    for (int i=1; i<=n; i++)
        totd += d[i];
    if(totd!=0)
        solutionExist = 0;
    for (int i=2; i<=n; i++)
        if((d[i]%n+n)%n!=(d[i-1]%n+n)%n)
            solutionExist = 0;

    if (solutionExist)
    {
        totm = 0;
        for(int i=1; i<=n; i++)
            totm = min(totm, d[i]);
        totm = -totm;
        for(int i=1; i<=n; i++)
            totabs[i] = (totm + d[i])/n;
        /*
        for (int i=1; i<=n; i++)
            printf("%d ", totabs[i]);
        puts("");
        */
        memset(cntabs, 0, sizeof(cntabs));
        memcpy(cntrep, ini, sizeof(cntrep));
        for (int cntm = 1; cntm<=totm&&solutionExist; cntm++)
        {
            int minpos=0;
            int zeronum=0;
            for(int i=1; i<=n; i++)
            {
                if(cntrep[i] == 0)
                    zeronum ++;
                if(cntabs[i] < totabs[i] && (minpos == 0 || cntrep[i] < cntrep[minpos]))
                    minpos = i;
            }
            if(zeronum>1)
            {
                solutionExist = 0;
                break;
            }
            ans[cntm] = minpos;
            for (int i=1; i<=n; i++)
                if(i==minpos)
                {
                    cntabs[i]++;
                    cntrep[i]+=n-1;
                }
                else
                {
                    cntrep[i]--;
                }
        }
    }
    if(solutionExist)
    {
        printf("%d\n", totm);
        for(int i=1; i<=totm; i++)
        {
            printf("%d", ans[i]);
            if(i != totm)
                printf(" ");
        }
        puts("");
    }
    else
    {
        printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
