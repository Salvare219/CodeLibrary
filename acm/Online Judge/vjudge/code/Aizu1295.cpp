#include <bits/stdc++.h>
using namespace std;


int h1[30],h2[30];
int main()
{
    int w,d;
    while(scanf("%d%d",&w,&d)&&w)
    {
        int x;
        memset(h1,0,sizeof(h1));
        memset(h2,0,sizeof(h2));
        for(int i=0;i<w;i++)
            scanf("%d",&x),h1[x]++;
        for(int i=0;i<d;i++)
            scanf("%d",&x),h2[x]++;
        int sum=0;
        for(int i=0;i<30;i++)
            sum+=max(h1[i],h2[i])*i;
        printf("%d\n",sum);
    }
    return 0;
}
