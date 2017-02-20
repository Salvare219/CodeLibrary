#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("knights.in","r",stdin);
    freopen("knights.out","w",stdout);
    int n;
    while(~scanf("%d",&n)&&n)
    {
        long long sx=1ll<<50,sy=1ll<<50;
        for(int i=0;i<n;i++)
        {
            long long x,y;
            scanf("%I64d%I64d",&x,&y);
            long long t=min(x/3,y/3);
            x-=3*t;y-=3*t;
            long long tx=t,ty=t;
            if(x>=2)x-=2,y--,tx++;
            tx+=x/2;
            ty+=y/2;
            sx=min(sx,tx);
            sy=min(sy,ty);
        }
        if(sx>sy)puts("Andrew wins the game");
        else puts("Peter wins the game");
    }
    return 0;
}
