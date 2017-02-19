#include<cstdio>

int num[1005],temp[1005],que[1005][2];
int ans;
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int z=0;z<t;z++)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=0;i<n;i++)
			scanf("%d",num+i);
		int tail=0,front=1,sta,end,s,e,con;
		que[0][0]=0;que[0][1]=n;
		while(tail<front)
		{
			sta=que[tail][0];end=que[tail][1];
			tail++;
			s=sta;e=end-1;con=0;
			for(int i=end-1;i>sta;i--)
			{
				if(num[i]>=num[sta]) 
				{
					temp[e--]=num[i];
					ans+=con;
				}
				else
				{
					temp[s++]=num[i];
					con++;
				}
			}
			ans+=con;
			temp[e]=num[sta];
			for(int i=sta;i<e;i++)
				num[i]=temp[e-i+sta-1];
			for(int i=e;i<end;i++)
				num[i]=temp[i];
			if(end-e>2) 
			{
				que[front][0]=e+1;
				que[front++][1]=end;
			}
			if(e-sta>1) 
			{
				que[front][0]=sta;
				que[front++][1]=e;
			}
		}
		printf("Scenario #%d:\n%d\n\n",z+1,ans);
	}
	return 0;
}