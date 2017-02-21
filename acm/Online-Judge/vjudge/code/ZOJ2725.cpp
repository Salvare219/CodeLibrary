#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


bool pn[1000050];
char str[9];
int main()
{
//    freopen("1.txt","r",stdin);
    int a;
    for(int i=1;i<1000000;i++)
        if(pn[i]==0)
        {
            for(int j=10;i*j<1000000;j*=10)
                for(int z=0;z<j/10;z++)
                    pn[i*j+z]=1;
            for(int j=1;j<=i;j*=10)
                for(int z=1;z+i/j%10<10;z++)
                    pn[i+z*j]=1;
        }
    while(scanf("%s",str)==1)
    {
        if(str[0]=='0') printf("Yes\n");
        else
        {
            sscanf(str,"%d",&a);
            if(pn[a]) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
