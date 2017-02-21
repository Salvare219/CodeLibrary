#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("arrange.in", "r", stdin);
    freopen("arrange.out", "w", stdout);

    int n;
    int counts[30];
    scanf("%d", &n);
    memset(counts, 0, sizeof(counts));
    for (int i=1; i<=n; i++)
    {
        char str[100];
        scanf("%s", str);
        counts[str[0]-'A']++;
    }

    int ans = 0;
    for (int i=0; i<26; i++)
        if (counts[i])
            ans++;
        else
            break;

    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
