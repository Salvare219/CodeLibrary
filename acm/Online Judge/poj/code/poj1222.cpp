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


int mat[35][35];
int ans[35];
void gauss()
{
    int fl;
    for(int i=0;i<30;i++)
    {
        fl=-1;
        for(int j=i;fl==-1;j++)
            if(mat[j][i]) fl=j;
        if(fl==-1) return ;
        if(fl!=i) for(int j=0;j<31;j++) swap(mat[i][j],mat[fl][j]);
        for(int j=i+1;j<30;j++)
            if(mat[j][i]) for(int z=i;z<31;z++) mat[j][z]^=mat[i][z];
    }
    memset(ans,0,sizeof(ans));
    ans[30]=1;
    for(int i=29;i>-1;i--)
        for(int j=30;j>i;j--)
            ans[i]^=mat[i][j]*ans[j];
}
int main()
{
    int n,ti=1;
    scanf("%d",&n);
    while(n--)
    {
        printf("PUZZLE #%d\n",ti++);
        memset(mat,0,sizeof(mat));
        for(int i=0;i<5;i++)
            for(int j=0;j<6;j++)
            {
                mat[i*6+j][i*6+j]=1;
                if(i) mat[i*6+j][i*6+j-6]=1;
                if(i<4) mat[i*6+j][i*6+j+6]=1;
                if(j) mat[i*6+j][i*6+j-1]=1;
                if(j<5) mat[i*6+j][i*6+j+1]=1;
            }
        for(int i=0;i<5;i++)
            for(int j=0;j<6;j++)
                scanf("%d",&mat[i*6+j][30]);
        gauss();
        for(int i=0;i<5;i++,putchar(10))
            for(int j=0;j<6;j++)
                if(j) printf(" %d",ans[i*6+j]);
                else printf("%d",ans[i*6+j]);

    }
    return 0;
}

