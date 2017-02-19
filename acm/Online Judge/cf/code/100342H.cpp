#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int n,m,i,j,k;
    scanf("%d%d",&n,&m);
    for(k=0,i=1,j=2;k<m;k++)
    {
        printf("%d %d %d\n",i,j,j-i-1);
        j++;
        if(j>n)
            i++,j=i+1;
    }
    return 0;
}
