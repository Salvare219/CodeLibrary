#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   


char str[40];
char lib[][3]={"A#","Bb","C#","Db","D#","Eb","F#","Gb","G#","Ab"};
int k[2]={1,-1};
int main()
{
	int t=0;	
	while(gets(str))
	{
		printf("Case %d: ",++t);
		int i=0,flag=0;
		for(i=0;str[i]!=' ';i++);
		str[i]=0;
		for(int j=0;j<10;j++) 
			if(strcmp(str,lib[j])==0) 
			{
				str[0]=lib[j+k[j%2]][0];
				str[1]=lib[j+k[j%2]][1];
				flag=1;
				break;
			}
		str[i]=' ';
		if(flag) printf("%s\n",str);
		else printf("UNIQUE\n");
	}
    return 0;
}