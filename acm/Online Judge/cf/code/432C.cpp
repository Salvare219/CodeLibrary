#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int prim[203000],k;
bool vis[200005];
void cal()
{
	for(int i=2;i<200001;i++)
	{
		if(vis[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<200005;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int ans[700050][2],cnt;
int sb[100050];
int wh[100050];
int v[100050];
int pre[100050];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    cal();
    memset(v,0x3f,sizeof(v));v[0]=0;
    for(int i=0;prim[i]<100005;i++)
        for(int j=prim[i]-1;j<100005;j++)
        {
            if(v[j]>v[j-(prim[i]-1)]+1)
                v[j]=v[j-(prim[i]-1)]+1,pre[j]=j-(prim[i]-1);
        }
    for(int i=0;i<n;i++)
        scanf("%d",sb+i),wh[sb[i]]=i;
    for(int i=0;i<n;i++)
    {
        int pos=wh[i+1];
        while(pos!=i)
        {
            int d=abs(pos-i);
            int c=d-pre[d];
            if(i>pos)
            {
                //printf("%d %d\n",pos+1,pos+c);
                ans[cnt][0]=pos+1;
                ans[cnt][1]=pos+c+1;
                cnt++;
                wh[sb[pos]]=pos+c;
                wh[sb[pos+c]]=pos;
                swap(sb[pos],sb[pos+c]);
                pos+=c;
            }
            else
            {
                //printf("%d %d\n",pos+1,pos-c);
                ans[cnt][0]=pos+1;
                ans[cnt][1]=pos-c+1;
                cnt++;
                wh[sb[pos]]=pos-c;
                wh[sb[pos-c]]=pos;
                swap(sb[pos],sb[pos-c]);
                pos-=c;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d\n",min(ans[i][0],ans[i][1]),max(ans[i][1],ans[i][0]));
    return 0;
}

