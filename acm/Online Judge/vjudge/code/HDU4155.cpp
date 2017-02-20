#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int num[7];
bool dfs(int sum)
{
    for(int i=0;i<6;i++)
    {
        if(num[i])
        {
            --num[i];
            if(sum+i+1<=31 && dfs(sum+i+1)==0) {++num[i];return 1;}
             ++num[i];
        }
    }
    return 0;
}
int main()
{
    char str[35];
    while(scanf("%s",str)!=EOF)
    {
        int sum=0;
        int l=strlen(str);
        for(int i=0;i<6;i++)
            num[i]=4;

        for(int i=0;str[i];i++)
            num[str[i]-'1']--,sum+=str[i]-'0';


        char ch;
        if(dfs(sum)) ch=(l%2)?'B':'A';
        else ch=(l%2)?'A':'B';
        printf("%s %c\n",str,ch);

    }
}

