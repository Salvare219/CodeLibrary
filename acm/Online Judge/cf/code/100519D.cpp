#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int a,b;scanf("%d%d",&a,&b);
    int z=-1;
    if(a>b)swap(a,b);
    for(int i=1;i<=1000;i++)
        if(i*i==a*a+b*b)
        {
            z=i;
            break;
        }
    if(z!=-1)puts("YES");
    else
    {
        for(int i=1;i<=1000;i++)
            if(i*i+a*a==b*b)
            {
                z=i;
                break;
            }
        if(z!=-1)puts("YES");
        else puts("NO");
    }
    return 0;
}

