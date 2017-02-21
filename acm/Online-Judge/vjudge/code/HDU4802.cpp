#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int credit[1010];
double score[1010];

int main()
{
    int n;
    while (cin>>n)
    {
        for (int i=1; i<=n; i++)
        {
            string str;
            cin>>credit[i]>>str;
            if (str == "P" || str == "N")
            {
                i--;
                n--;
            }
            else if (str == "A")
                score[i] = 4.0;
            else if (str == "A-")
                score[i] = 3.7;
            else if (str == "B+")
                score[i] = 3.3;
            else if (str == "B")
                score[i] = 3.0;
            else if (str == "B-")
                score[i] = 2.7;
            else if (str == "C+")
                score[i] = 2.3;
            else if (str == "C")
                score[i] = 2.0;
            else if (str == "C-")
                score[i] = 1.7;
            else if (str == "D")
                score[i] = 1.3;
            else if (str == "D-")
                score[i] = 1.0;
            else if (str == "F")
                score[i] = 0.0;
        }
        if (n == 0)
            printf("0.00\n");
        else
        {
            double ans1 = 0.0, ans2 = 0.0;
            for (int i=1; i<=n; i++)
                ans1 += credit[i] * score[i], ans2 += credit[i];
            printf("%.2f\n", ans1/ans2);
        }
    }
    return 0;
}
