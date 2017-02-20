#include <cstdio>
#include <cstring>
#include <algorithm>

#define eps (1e-5)
using namespace std;
int ans;
int x, y;

void dfs(double left, double right, int cnt, int cntans)
{
    if (left < eps)
        ans = cntans;
    if (cnt > x)
        return ;

    for (int i = (right * cnt - eps); i>=0; i--)
    {
        double h = ((double)i)/cnt;
        if (h > right)
            continue;
        if (left < h + eps)
            ans = min(ans, cntans + i);
        else
        {
            int temp = y;
            for (int j = cnt + 1; j <= x; j++)
            {
                int tempans = (left - h)*j;
                temp = min(temp, tempans);
            }
            if (i + temp + cntans > ans)
                break;
            dfs(left - h, right - h, cnt + 1, cntans + i);
        }
    }
    return ;
}

int main()
{
    while(scanf("%d%d", &x, &y) == 2)
    {
        if (y < x)
            printf("-1\n");
        else if (x == 1)
            printf("%d\n", y - 1);
        else
        {
            ans = y;
            dfs(((double)y-x)/x, ((double)y-x+1)/x, 1, x-1);
            printf("%d\n", ans);
        }
    }
    return 0;
}
