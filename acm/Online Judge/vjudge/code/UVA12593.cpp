#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int mat[105][105],n;
const int mod=10007;
void mult(int a[][105],int b[][105],int c[][105])
{
	int d[105][105]={0};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=d[i][j];
}
void pow_mat(int a[][105],int k)
{
	int ii[105][105]={0};
	for(int i=0;i<n;i++)
		ii[i][i]=1;
	while(k)
	{
		if(k&1) mult(a,ii,ii);
		k>>=1;
		mult(a,a,a);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=ii[i][j];
}
int an[200];
int main()
{
    int t;scanf("%d",&t);
    int ti=1;
    while(t--)
    {
        printf("Case %d: ",ti++);
        int nn,k;
        scanf("%d%d",&nn,&k);
        if(nn==1)puts("2");
        else if(nn==2)puts("2");
        else
        {
            memset(an,0,sizeof(an));
            an[1]=1;n=k;
            for(int i=1;i<n;i++)
                for(int j=0;j<n;j++)
                    if(i-1==j)mat[i][j]=1;
                    else mat[i][j]=0;
            for(int i=0;i<n;i++)
                mat[0][i]=1;mat[0][0]=0;
            pow_mat(mat,nn-2);
            int ans=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    ans=(ans+mat[i][j]*an[j])%mod;
            ans=(ans+mod)%mod;
            printf("%d\n",(2*ans)%mod);
        }
    }
    return 0;
}
