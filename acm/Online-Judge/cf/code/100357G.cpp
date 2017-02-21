#include <bits/stdc++.h>

using namespace std;

int tohash1[30];
int tohash2[30];

char str[5000];
int n;
int nextt[5000];
int firstpos[30];

int calz(char a[], int n, int z[])
{
    z[0]=0;
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        z[i] = 0;
        if (i <= r)
            z[i] = min(z[i - l], r - i + 1);
        memset(tohash1, -1, sizeof(tohash1));
        memset(tohash2, -1, sizeof(tohash2));
        for (int j=0; j<26; j++)
            if (firstpos[j] != -1 && firstpos[j] < z[i])
            {
                int index2 = a[i + firstpos[j]] - 'a';
                tohash1[j] = index2;
                tohash2[index2] = j;
            }

        while (i + z[i] < n)// && a[z[i]] == a[i + z[i]])
        {
            int index1 = a[z[i]] - 'a';
            int index2 = a[i+z[i]] - 'a';
            if ((tohash1[index1] == -1 && tohash2[index2] == -1) || (tohash1[index1] == index2 && tohash2[index2] == index1))
            {
                tohash1[index1] = index2;
                tohash2[index2] = index1;
                ++z[i];
            }
            else
                break;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return 1;
}

pair<int, int> dict[5000];

int main()
{
    freopen("pattern.in", "r", stdin);
    freopen("pattern.out", "w", stdout);
    while (scanf("%s", str) == 1)
    {
        n = strlen(str);

        int anst = n;
        int ansi = 0;
        int ansl = n;
        //int ansj = 1;
        for (int i=0; i<n; i++)
        {

            memset(firstpos, -1, sizeof(firstpos));
            for (int j = 0; j < n-i; j++)
            {
                int index = str[i+j] - 'a';
                if (firstpos[index] == -1)
                    firstpos[index] = j;
            }

            calz(str+i, n-i, nextt);
            nextt[0] = n-i;
            for(int j=0; j<(n-i); j++)
                dict[j] = make_pair(-nextt[j], -j);
            sort(dict, dict+(n-i));
            for (int j=0; j<(n-i); j++)
            {
                if ((j+1)*(-dict[j].first) > anst)
                {
                    anst = (j+1)*(-dict[j].first);
                    ansi = i-dict[j].second;
                    ansl = -dict[j].first;
                    //ansj = j+1;
                }
            }
        }

        //printf("%d %d %d %d\n", ansi, ansl, anst, ansj);
        for (int i=0; i<ansl; i++)
            printf("%c", str[ansi + i]);
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
