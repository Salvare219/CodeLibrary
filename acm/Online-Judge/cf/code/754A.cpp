#include<bits/stdc++.h>
using namespace std;


int a[200];
int main()
{
    int n,sum=0,f=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sum+=a[i];
        if(a[i])f=1;
    }
    if(f==0)
        puts("NO");
    else
    {
        puts("YES");
        if(sum)
            printf("1\n1 %d\n",n);
        else
        {
            int z=0;
            for(int i=0;i<n;i++)
            {
                z+=a[i];
                if(z)
                {
                    f=i+1;
                    break;
                }
            }
            printf("2\n1 %d\n%d %d\n",f,f+1,n);
        }
    }
	return 0;
}
