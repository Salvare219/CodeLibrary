#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,ty=80;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int s;
            scanf("%d",&s);
            if(s==1)
            {
                if((i==0 || i==n-1) && (j==0 || j==m-1)) ty=min(ty,0);
                else if(i==0 || i==n-1) ty=min(ty,1);
                else if(j==0 || j==m-1) ty=min(ty,1);
                else ty=min(ty,2);
            }
        }
    if(ty==0) printf("1\n");
    else if(ty==1) printf("2\n");
    else printf("4\n");
    return 0;
}
