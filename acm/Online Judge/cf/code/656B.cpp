#include <bits/stdc++.h>
using namespace std;



int a[55];
int b[55];
int main()
{
    int n;scanf("%d",&n);
    int sum=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sum=sum/__gcd(a[i],sum)*a[i];
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",b+i);
    }
    int k=0;
    for(int i=0;i<sum;i++)
        for(int j=0;j<n;j++)
            if(i%a[j]==b[j])
        {
            k++;
            break;
        }
    printf("%.10f\n",1.0*k/sum);
    return 0;
}
