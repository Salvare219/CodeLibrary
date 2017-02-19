#include <bits/stdc++.h>

using namespace std;

inline bool Int(int &a)
{
    char c=0;c=getchar();a=0;
    if(c<' ')
        return 0;
    while(c<'0')c=getchar();
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
    return c>=' ';
}


char str[100010];
int n;
double data[100100];
int main()
{
    //freopen("input.txt", "r", stdin);
    int d;
    while (Int(d))
    {
        //puts(str);

        double p;
        n = 0;

        int tmp;
        Int(tmp);
        p=tmp;
        while(Int(tmp))
        {
            data[n++]=tmp;
        }
        data[n++] = tmp;

        int ans = d+1;
        if (n<=d+1)
        {
            double s4 = data[n-1];
            double s3 = data[n-2];
            double s2 = data[n-3];
            double s1 = data[n-4];
            double a, b;
            if (abs(s3 * s1 - s2 * s2) > 1e-8)
            {
                a = (s4 * s1 - s3 * s2)/(s3 * s1 - s2 * s2);
                b = (s4 * s2 - s3 * s3)/(s2 * s2 - s1 * s3);
            }
            else
            {
                if (abs(data[n-1])<1e-8)
                    a = 0.0;
                else
                    a = data[n-1]/data[n-2];
                b = 0.0;
            }
            for (int i=0; i<=d; i++)
            {
                if (i>=n)
                    data[i] = a * data[i-1] + b * data[i-2];
                if (data[i] > p)
                    break;
                ans --;
            }
        }
        else
        {
            for (int i=0; i<=d; i++)
            {
                if (data[i] > p)
                    break;
                ans --;
            }
        }

        if (ans == d+1)
            printf("The spider is going to fall!\n");
        else if ( ans <= 0 )
            printf("The spider may fall!\n");
        else
        {
            printf("%d\n", ans);
        }
        /*
        printf("%d\n", n);
        for (int i=0; i<n; i++)
            printf("%d ", data[i]);
        printf("\n");
        */
    }
    fclose(stdin);
    return 0;
}
