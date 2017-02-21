#include <bits/stdc++.h>

using namespace std;

char str[110][110];
int went[110][110];

int main()
{
    int CAS;
    scanf("%d", &CAS);
    while (CAS--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(went, 0, sizeof(went));
        for (int i=0; i<n; i++)
            scanf("%s", str[i]);
        int counts = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (!went[i][j])
                {
                    if (str[i][j] == '-')
                    {
                        counts++;
                        int s = i;
                        int t = j;
                        while (s>=0 && s<n && t>=0 && t<m && str[s][t] == '-')
                        {
                            went[s][t] = 1;
                            t++;
                        }
                    }
                    else if (str[i][j] == '|')
                    {
                        counts++;
                        int s = i;
                        int t = j;
                        while (s>=0 && s<n && t>=0 && t<m && str[s][t] == '|')
                        {
                            went[s][t] = 1;
                            s++;
                        }
                    }
                    else if (str[i][j] == '\\')
                    {
                        counts++;
                        int s = i;
                        int t = j;
                        while (s>=0 && s<n && t>=0 && t<m && str[s][t] == '\\')
                        {
                            went[s][t] = 1;
                            s++;
                            t++;
                        }
                    }
                    else if (str[i][j] == '/')
                    {
                        counts++;
                        int s = i;
                        int t = j;
                        while (s>=0 && s<n && t>=0 && t<m && str[s][t] == '/')
                        {
                            went[s][t] = 1;
                            s++;
                            t--;
                        }
                    }
                }
        if (counts==1)
            printf("CORRECT\n");
        else
            printf("INCORRECT\n");
    }
    return 0;
}
