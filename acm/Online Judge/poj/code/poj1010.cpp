#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int stam[100],ans[20],peo,val,flag;
int cmp(void const *a,void const *b)
{
	int *c=(int*)a;
	int *d=(int*)b;
	return (*c>*d)?1:-1;
}
int weit(int *va)
{
	int num=4;
	for(int i=0;i<4;i++)
		if(va[i]==-1) num--;
	int temp=4-num;
	for(int i=4-num;i<3;i++)
		if(va[i]==va[i+1]) num--;
	return num*10000+temp*100;
}
int choose(int num)
{
	int va[5];
	for(va[0]=-1;va[0]<num;va[0]++)
		for(va[1]=va[0];va[1]<num;va[1]++)
			for(va[2]=va[1];va[2]<num;va[2]++)
				for(va[3]=va[2];va[3]<num;va[3]++)
				{
					int sum=0;
					for(int i=0;i<4;i++)
						if(va[i]==-1) continue;
						else sum+=stam[va[i]];
					if(peo==sum)
					{
						int now=weit(va)+stam[va[3]];
						if(now>val)
						{
							flag=0;
							val=now;
							for(int i=0;i<4;i++) ans[i]=va[i];
						}
						else if(now==val)
						{
							flag=1;
						}
					}
	
				}
	return 0;
}
int main()
{
	while(scanf("%d",stam)==1)
	{
		int i=1;
		while(scanf("%d",stam+i))
		{
			if(!stam[i++]) break;
		}
		qsort(stam,i-1,sizeof(stam[0]),cmp);
		while(scanf("%d",&peo))
		{
			if(!peo) break;
			val=0;flag=0;
			choose(i-1);
			if(flag) printf("%d (%d): tie\n",peo,val/10000);
			else 
			{
				if(val) 
				{
					printf("%d (%d):",peo,val/10000);
					for(int i=0;i<4;i++)
						if(ans[i]==-1) continue;
						else printf(" %d",stam[ans[i]]);
					putchar(10);
				}
				else printf("%d ---- none\n",peo);
			}
		}
	}
	return 0;
}