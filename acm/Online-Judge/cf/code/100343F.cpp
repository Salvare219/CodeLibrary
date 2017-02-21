#include <bits/stdc++.h>

#define maxlen 200010
using namespace std;

char aim[maxlen],tofind[maxlen];
int nextt[maxlen];
int bucket[200];
int AimSampos[maxlen];
int TofindSampos[maxlen];
vector<int> ans;

int same( char aim[], int AimSampos[], char tofind[], int TofindSampos[],int i, int j)
{
    if (TofindSampos[j] == -1 && (AimSampos[i] == -1 || i - AimSampos[i] > j))
        return 1;
    else if (TofindSampos[j] == -1 && (AimSampos[i] == -1 || i - AimSampos[i] > j))
        return 0;
    else if (j - TofindSampos[j] == i - AimSampos[i])
        return 1;
    else
        return 0;
}

int calnextt()
{
    int i,j;
    nextt[1]=0;
    j=0;
    for (i=2;tofind[i-1];i++)
    {
        while  ((j>0)&&!same(tofind, TofindSampos, tofind, TofindSampos, i-1, j))
            j=nextt[j];
        nextt[i]=(j= (j+same(tofind, TofindSampos, tofind, TofindSampos, i-1, j)) );
    }
    return 0;
}

int kmp(char aim[], int AimSampos[], char tofind[], int TofindSampos[], int nextt[])
{
    int i,j;
    j=0;
    for (i=1;aim[i-1];i++)
    {
        while (j>0&&!same(aim, AimSampos, tofind, TofindSampos, i-1, j))
            j=nextt[j];
        if (same(aim, AimSampos, tofind, TofindSampos, i-1, j))
            j++;
        if (!tofind[j])
        {
            ans.push_back(i-j+1);
            j=nextt[j];
        }
    }
    return 0;
}

int main()
{
    freopen("substring.in", "r", stdin);
    freopen("substring.out", "w", stdout);

    gets(aim);
    gets(tofind);

    memset(bucket, -1, sizeof(bucket));
    for (int i=0; aim[i]; i++)
    {
        AimSampos[i] = bucket[(int)aim[i]];
        bucket[(int)aim[i]] = i;
    }

    memset(bucket, -1, sizeof(bucket));
    for (int i=0; tofind[i]; i++)
    {
        TofindSampos[i] = bucket[(int)tofind[i]];
        bucket[(int)tofind[i]] = i;
    }

    calnextt();
    /*
    for (int i=1; tofind[i-1]; i++)
        printf("%d\n", nextt[i]);
        */
    kmp(aim, AimSampos, tofind, TofindSampos, nextt);
    printf("%d\n", (int)ans.size());
    for (int i = 0; i<(int)ans.size(); i++)
        printf("%d%c", ans[i], (i==((int)ans.size()-1))?'\n':' ');

    fclose(stdin);
    fclose(stdout);
    return 0;
}
