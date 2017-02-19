#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("energy.in", "r", stdin);
    freopen("energy.out", "w" ,stdout);

    int tot, cnt1, cnt2, ocu;
    scanf("%d", &tot);
    char str[100100];
    scanf("%s", str);
    long long ans = 0;
    cnt1 = cnt2 = ocu = 0;
    for (int i=0; str[i]; i++)
    {
        if (str[i] == '1')
        {
            if (ocu + 1 <= tot)
            {
                cnt1 ++;
                ocu +=1;
            }
            else if (cnt2)
            {
                cnt2--;
                cnt1++;
                ocu--;
            }
        }
        else
        {
            if (ocu + 2 <= tot)
            {
                cnt2 ++;
                ocu +=2;
            }
        }
        ans += cnt1 + cnt2;
        //cout<<cnt1<<" "<<cnt2<<endl;
    }
    cout<<ans<<endl;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
