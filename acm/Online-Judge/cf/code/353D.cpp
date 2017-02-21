#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char s[5000000];
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s",s);
    int n=strlen(s);
    int las=0,con=0;
    for(int i=0;i<n;i++)
        if(s[i]=='F')
        {
            int dis=i-con;
            con++;
            if(dis==0) continue;
            else
            {
                if(las>=dis) las=las+1;
                else las=dis;
            }
        }
    printf("%d\n",las);
    return 0;
}
