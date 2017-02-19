#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
vector<int> gra[505];
int n;
bool vis[505];
int p[505],mat[505];
bool find(int s)
{
	for(int i=0;i<gra[s].size();i++)
		if(vis[gra[s][i]]==0&&p[gra[s][i]]!=s&&p[s]!=gra[s][i])
		{
			vis[gra[s][i]]=1;
			if(p[gra[s][i]]==0 || find(p[gra[s][i]]))
			{
			    mat[s]=gra[s][i];
				p[gra[s][i]]=s;
				return 1;
			}
		}
	return 0;
}
int max_match()
{
	int ans=0;
	memset(p,0,sizeof(p));
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=find(i);
	}
	return ans;
}
int use[500];
vector<int>fin[500];
int a[500];
int prim[53000],k;
bool v[50005];
void cal()
{
	for(int i=2;i<50001;i++)
	{
		if(v[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<50005;j++)
		{
			v[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);cal();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        for(int j=1;j<i;j++)
            if(v[a[i]+a[j]]==0)
                gra[i].push_back(j),gra[j].push_back(i);
    }
    int ans=max_match();
    if(ans==n)
    {
        int how=0;
        for(int i=1;i<=n;i++)
            if(use[i]==0)
            {
                int f=mat[i];use[i]=1;
                fin[how].push_back(i);
                while(f!=i)
                {
                    use[f]=1;
                    fin[how].push_back(f);
                    f=mat[f];
                }
                how++;
            }
        printf("%d\n",how);
        for(int i=0;i<how;i++)
        {
            printf("%d ",fin[i].size());
            for(int j=0;j<fin[i].size();j++)
                printf("%d ",fin[i][j]);puts("");
        }
    }
    else puts("Impossible");
    return 0;
}
