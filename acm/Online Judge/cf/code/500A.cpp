#include <bits/stdc++.h>
using namespace std;


int a[1000050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,t;scanf("%d%d",&n,&t);
    for(int i=1;i<n;i++)
        scanf("%d",a+i);
    int now=1;
    while(now<t)
    {
        now=now+a[now];
    }
    puts(now==t?"Yes":"No");
    return 0;
}
