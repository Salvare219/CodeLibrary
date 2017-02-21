#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[105][105];
int row[105],col[105];
int main()
{
	int n;
	while(scanf("%d",&n))
	{
	    if(n==0) break;
	    memset(row,0,sizeof(row));
	    memset(col,0,sizeof(col));
	    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                row[i]+=a[i][j],col[j]+=a[i][j];
        int x,y,t=0,ti=0;
        for(int i=0;i<n;i++)
            if(row[i]&1) x=i,t++;
        for(int i=0;i<n;i++)
            if(col[i]&1) y=i,ti++;
        if(ti==0 && t==0) printf("OK\n");
        else if(ti==1 && t==1) printf("Change bit (%d,%d)\n",x+1,y+1);
        else printf("Corrupt\n");
	}
	return 0;
}
