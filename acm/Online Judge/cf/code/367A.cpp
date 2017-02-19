#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char s[100050];
int tot[100050][3];
int sb[1000];
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s",s);sb['z']=0;
    sb['y']=1;sb['x']=2;
    for(int i=0;s[i];i++)
    {
        tot[i+1][0]=tot[i][0];
        tot[i+1][1]=tot[i][1];
        tot[i+1][2]=tot[i][2];
        tot[i+1][sb[s[i]]]++;
    }
    int n;scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        int a[3]={tot[y][0]-tot[x-1][0],tot[y][1]-tot[x-1][1],tot[y][2]-tot[x-1][2]};
        if(y-x<2)puts("YES");
        else
        {
            int d=max(max(a[0],a[1]),a[2]);
            bool f=0;
            for(int j=0;j<3;j++)
                if(a[j]==d)
                {
                    int a1=j,a2=(j+1)%3,a3=(j+2)%3;
                    if(a[a1]==a[a2])
                    {
                        if(a[a3]==a[a2]||a[a3]==a[a2]-1)f=1;
                    }
                    else if(a[a1]==a[a2]+1)
                    {
                        if(a[a3]==a[a2])f=1;
                    }
                }
            if(f)puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
