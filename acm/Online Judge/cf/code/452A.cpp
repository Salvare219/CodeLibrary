#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char lib[][20]=
{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main()
{
    int n;
    char s[20];
    scanf("%d%s",&n,s);
    for(int i=0;i<8;i++)
    {
        int m=strlen(lib[i]);
        if(m==n)
        {
            int f=0;
            for(int j=0;lib[i][j];j++)
                if(s[j]=='.');
                else
                {
                    if(s[j]!=lib[i][j])
                    {
                        f=1;
                        break;
                    }
                }
            if(f==0)
            {
                puts(lib[i]);
                return 0;
            }
        }
    }
    return 0;
}


