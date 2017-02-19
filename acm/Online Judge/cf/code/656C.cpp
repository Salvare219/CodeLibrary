#include<bits/stdc++.h>
using namespace std;


int main()
{
    char s[100];
	scanf("%s",s);
	int l=strlen(s);
	int sum=0;
	for(int i=0;i<l;i++)
		if(s[i]>='A'&&s[i]<='Z')
			sum+=s[i]-'A'+1;
		else if(s[i]>='a'&&s[i]<='z')
			sum-=s[i]-'a'+1;
	printf("%d\n",sum);
	return 0;
}
