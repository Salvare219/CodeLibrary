#include<bits/stdc++.h>
using namespace std;

bool a[105],b[105];

int main()
{
    int n,k,z,i;
    bool *x,*y;
    x=a;y=b;
    x[0]=1;
    for(scanf("%d%d",&n,&k);n--;)
    {
        scanf("%d",&z);
        memset(y,0,sizeof(a));
        for(i=0;i<k;i++)
            if(x[i])
                y[((i+z)%k+k)%k]=y[((i-z)%k+k)%k]=1;
        swap(x,y);
    }
    puts(x[0]?"Divisible":"Not divisible");
    return 0;
}
