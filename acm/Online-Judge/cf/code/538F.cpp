#include<bits/stdc++.h>
using namespace std;


int n;
int a[200050];
int sum[200050];
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=2;i<=n;i++)
    {
        int m=i-2,k;
        for(int j=1;j<n;j=k+1)
        {
            if(m>=j)
            {
                k=m/(m/j);
                if(a[i]<a[m/j+1])
                    sum[j-1]--,sum[k]++;
            }
            else
            {
                if(a[i]<a[m/j+1])
                    sum[j-1]--,sum[n-1]++;
                break;
            }
        }
    }
    for(int i=n-1;i>=1;i--)
        sum[i]+=sum[i+1];
    for(int i=1;i<n;i++)
        printf("%d ",sum[i]);puts("");
    return 0;
}

