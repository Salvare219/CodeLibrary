#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[1000000];
int main()
{
//    freopen("1.txt","r",stdin);
    int t,x,y,x1,y1;
    int ans=-1;
    scanf("%d%d%d%d%d",&t,&x,&y,&x1,&y1);
    scanf("%s",str);
    for(int i=0;i<t;i++)
    {
        if(str[i]=='N')
        {
            if(y1>y) y++;
        }
        if(str[i]=='S')
        {
            if(y1<y) y--;
        }
        if(str[i]=='W')
        {
            if(x1<x) x--;
        }
        if(str[i]=='E')
        {
            if(x1>x) x++;
        }
        if(x==x1 && y==y1)
        {
            ans=i+1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}





























