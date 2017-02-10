int prim[20005],k;
int mi[20005];
bool vis[20005];
void cal()
{
	for(int i=2;i<20001;i++)
	{
		if(vis[i]==0) prim[k++]=i,mi[i]=i;
		for(int j=0;j<k && prim[j]*i<20005;j++)
		{
			vis[prim[j]*i]=1;
			mi[prim[j]*i]=prim[j];
			if(i%prim[j]==0) break;
		}
	}
}