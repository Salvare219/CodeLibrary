#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    char s[100];
    scanf("%s",s);
    int sum=0;
    for(int i=0;i<strlen(s);i++)
        if(s[i]<='9'&&s[i]>='0')
        {
            if(s[i]=='1'&&s[i+1]=='0')
                sum+=10,i++;
            else
                sum+=s[i]-'0';
        }
    printf("%d\n",sum+1);
	return 0;
}
