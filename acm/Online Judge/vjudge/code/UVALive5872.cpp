#include<bits/stdc++.h>
using namespace std;


int ver[26];
char ope[6]=")+-*(";
int level[6]={1,2,2,3,4};
void cal(long long sta1[],char sta2[],int *fron1,int *fron2)
{
	char ch=ope[sta2[*fron2-1]];
	long long num1=sta1[*fron1-2],num2=sta1[*fron1-1];
	*fron1=*fron1-2;
	(*fron2)--;
	if(ch=='+') sta1[(*fron1)++]=num1+num2;
	else if(ch=='-') sta1[(*fron1)++]=num1-num2;
	else sta1[(*fron1)++]=num1*num2;
}
char *p,stack2[95],s[100];
long long stack1[95],ans;
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i=0;i<26;i++)
		ver[i]=i+27;
	getchar();
	while(t--)
	{
		for(int i=0;i<2;i++)
		{
			int fron1=0,fron2=0;
			gets(s);
			int g=strlen(s);
			for(int j=0;j<g;j++)
			{
				if(isalpha(s[j]))
				{
					s[j]=tolower(s[j]);
					stack1[fron1++]=ver[s[j]-'a'];
				}
				else if(isdigit(s[j]))
				{
					stack1[fron1++]=s[j]-'0';
				}
				else if(p=strchr(ope,s[j]))
				{
					int lev=level[p-ope];
					while(fron1&&lev<=level[stack2[fron2-1]]&&stack2[fron2-1]!=4)
						cal(stack1,stack2,&fron1,&fron2);
					stack2[fron2++]=p-ope;
					if(stack2[fron2-1]==0 &&stack2[fron2-2]==4)
						fron2-=2;
				}
			}
			if(fron1==2)cal(stack1,stack2,&fron1,&fron2);
			else stack1[1]=stack1[1]*stack1[2];
			if(i==0) ans=stack1[0];
			else
			{
				if(ans==stack1[0]) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}
