#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int st[100050];
int main()
{
    int n,g;
    while(scanf("%d%d",&n,&g)==2)
    {
        int sum=0,x,y,k=0,p=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x>y)sum+=3;
            else if(x==y) sum++,p++;
            else st[k++]=y-x;
        }
        sort(st,st+k);
        if(p>=g)
        {
            sum+=g*2;
            printf("%d\n",sum);
        }
        else
        {
            sum+=p*2;
            g-=p;
            for(int i=0;i<k;i++)
                if(g<st[i])break;
                else
                {
                    g-=st[i];
                    sum++;
                    if(g)g--,sum+=2;
                }
            printf("%d\n",sum);
        }
    }
}