#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool v[1<<19];
vector<int>a[1<<19];
bool cal(int s)
{
    if(v[s]) return a[s].size();
    v[s]=1;
    for(int i=0;i<19;i++)
        if(s&(1<<i))
        {
            int x=s,y;
            for(int j=1;j*(i+2)<21;j++)
                if(x&(1<<j*(i+2)-2)) x^=1<<j*(i+2)-2;
            for(int j=0;j<19;j++)
                if((x&(1<<j))==0)
                for(int z=j+1;j+z<17;z++)
                    if((x&(1<<z))==0)
                    {
                        y=1<<j+z+2;
                        if(y&x)x^=y;
                    }
            if(cal(x)==0) a[s].push_back(i+2);
        }
    return a[s].size();
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int s=0,x,n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&x),s|=1<<x-2;
        printf("Scenario #%d:\n",ti++);
        if(cal(s))
        {
            printf("The winning moves are:");
            for(int i=0;i<a[s].size();i++)
                printf(" %d",a[s][i]);
            printf(".\n\n");
        }
        else printf("There is no winning move.\n\n");
    }
    return 0;
}