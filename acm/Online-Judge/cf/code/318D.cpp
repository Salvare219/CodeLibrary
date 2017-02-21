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


int maz[1000][1000];
int main()
{
  //  freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    maz[500][500]=n;
    queue<int> q;
    q.push(500500);
    bool inq[1000][1000]={0};
    while(!q.empty())
    {
        int a=q.front(),b;
        q.pop();
        int x=a/1000,y=a%1000;
        inq[x][y]=0;
        a=maz[x][y]/4;
        maz[x][y]=maz[x][y]%4;
        maz[x+1][y]+=a;
        if(maz[x+1][y]>=4 && inq[x+1][y]==0) q.push(x*1000+y+1000),inq[x+1][y]=1;
        maz[x-1][y]+=a;
        if(maz[x-1][y]>=4 && inq[x-1][y]==0) q.push(x*1000+y-1000),inq[x-1][y]=1;
        maz[x][y+1]+=a;
        if(maz[x][y+1]>=4 && inq[x][y+1]==0) q.push(x*1000+y+1),inq[x][y+1]=1;
        maz[x][y-1]+=a;
        if(maz[x][y-1]>=4 && inq[x][y-1]==0) q.push(x*1000+y-1),inq[x][y-1]=1;
    }
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        x+=500;y+=500;
        if(x<0 || x>999 || y<0 || y>999) printf("0\n");
        else printf("%d\n",maz[x][y]);
    }
}
