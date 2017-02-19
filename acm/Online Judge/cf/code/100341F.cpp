#include <bits/stdc++.h>

using namespace std;

struct spg
{
    public:
    int dp[4];
    spg()
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = -1;
    }
    spg(int series, spg a1, spg a2)
    {
        dp[0] = -1;
        dp[1] = -1;
        dp[2] = -1;
        dp[3] = -1;
        if (series)
        {
            if (a1.dp[0] != -1 && a2.dp[0] != -1)
                dp[0] = max(dp[0], a1.dp[0] + a2.dp[0]);
            if (a1.dp[1] != -1 && a2.dp[2] != -1)
                dp[0] = max(dp[0], a1.dp[1] + a2.dp[2] - 1);

            if (a1.dp[0] != -1 && a2.dp[1] != -1)
                dp[1] = max(dp[1], a1.dp[0] + a2.dp[1]);
            if (a1.dp[1] != -1 && a2.dp[3] != -1)
                dp[1] = max(dp[1], a1.dp[1] + a2.dp[3] - 1);

            if (a1.dp[2] != -1 && a2.dp[0] != -1)
                dp[2] = max(dp[2], a1.dp[2] + a2.dp[0]);
            if (a1.dp[3] != -1 && a2.dp[2] != -1)
                dp[2] = max(dp[2], a1.dp[3] + a2.dp[2] - 1);

            if (a1.dp[2] != -1 && a2.dp[1] != -1)
                dp[3] = max(dp[3], a1.dp[2] + a2.dp[1]);
            if (a1.dp[3] != -1 && a2.dp[3] != -1)
                dp[3] = max(dp[3], a1.dp[3] + a2.dp[3] - 1);
        }
        else
        {
            if (a1.dp[0] != -1 && a2.dp[0] != -1)
                dp[0] = max(dp[0], a1.dp[0] + a2.dp[0]);

            if (a1.dp[1] != -1 && a2.dp[1] != -1)
                dp[1] = max(dp[1], a1.dp[1] + a2.dp[1] - 1);

            if (a1.dp[2] != -1 && a2.dp[2] != -1)
                dp[2] = max(dp[2], a1.dp[2] + a2.dp[2] - 1);

            if (a1.dp[3] != -1 && a2.dp[3] != -1)
                dp[3] = max(dp[3], a1.dp[3] + a2.dp[3] - 2);
        }
    }
};

char str[100010];

spg stack1[100010];

int top1, top2;
int stack2[100010];

int main()
{
    freopen("independent.in", "r", stdin);
    freopen("independent.out", "w", stdout);
    scanf("%s", str);
    top1 = 0;
    top2 = 0;
    for (int i=0; str[i]; i++)
    {
        if (str[i] == 'S')
            stack2[++top2] = 1;
        else if (str[i] == 'P')
            stack2[++top2] = 0;
        else if (str[i] == 'g')
        {
            stack1[++top1] = spg();
            stack2[++top2] = 2;
        }
        while (top2>=2 && stack2[top2] == 2 && stack2[top2-1] == 2)
        {
            spg temp1 = stack1[top1--];
            top2--;
            spg temp2 = stack1[top1--];
            top2--;
            stack1[++top1] = spg(stack2[top2--], temp1, temp2);
            stack2[++top2] = 2;
        }
    }
    int ans = 0;
    for (int i=0; i<=3; i++)
        ans = max(ans, stack1[1].dp[i]);
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
