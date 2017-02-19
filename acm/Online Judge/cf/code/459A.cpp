#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int x,y,x1,y1;
    scanf("%d%d%d%d",&x,&y,&x1,&y1);
    if(x==x1&&y==y1)
    {
        printf("-1\n");
    }
    else
    {
        if(x==x1)
        {
            int l=abs(y-y1);
            printf("%d %d %d %d\n",x+l,y,x+l,y1);
        }
        else if(y==y1)
        {
            int l=abs(x-x1);
            printf("%d %d %d %d\n",x,y+l,x1,y1+l);
        }
        else
        {
            int l1=abs(x-x1),l2=abs(y-y1);
            if(l1!=l2)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d %d %d %d\n",x,y1,x1,y);
            }
        }
    }
    return 0;
}
