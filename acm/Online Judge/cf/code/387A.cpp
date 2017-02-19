#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int a,b,c,d;
    scanf("%d:%d",&a,&b);
    scanf("%d:%d",&c,&d);
    int x,y;
    for(int i=0;i<24;i++)
        for(int j=0;j<60;j++)
        {
            if((j+d)%60==b)
            {
                int s=0;
                if(j+d>=60)s=1;
                if((i+c+s)%24==a)
                {
                    x=i;y=j;
                }
            }
        }
    printf("%02d:%02d\n",x,y);
	return 0;
}

