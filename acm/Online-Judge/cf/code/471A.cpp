#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int c[66]={0};
    int x;
    for(int i=0;i<6;i++)
        scanf("%d",&x),c[x]++;
    int a=-1,b=-1,f=0;
    for(int i=1;i<10;i++)
    {
        if(c[i]>=4)
        {
            c[i]-=4;
            f=1;
        }
        while(c[i])
        {
            c[i]--;
            if(a==-1)a=i;
            else if(b==-1)b=i;
        }
    }
    if(f)
    {
        if(a>b)swap(a,b);
        if(a<b)puts("Bear");
        else puts("Elephant");
    }
    else puts("Alien");
    return 0;
}
