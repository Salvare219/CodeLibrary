#include <bits/stdc++.h>

using namespace std;

char stra[200], strb[200];

int main()
{
    int CAS1;
    scanf("%d", &CAS1);
    for (int CAS = 1; CAS <= CAS1; CAS++)
    {
        scanf("%s%s", strb, stra);
        int a=0, b=0, c=0, d=0;
        for (int i = 0; stra[i]; i++)
            if (stra[i] == '0' && strb[i] == '1')
                a++;
            else if (stra[i] == '1' && strb[i] == '0')
                b++;
            else if (stra[i] == '0' && strb[i] == '?')
                c++;
            else if (stra[i] == '1' && strb[i] == '?')
                d++;
        int ans = max(a, b) + c + d;
        if (a> b+d)
            ans = -1;
        printf("Case %d: %d\n", CAS, ans);
    }
    return 0;
}
