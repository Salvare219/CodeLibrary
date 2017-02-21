#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char lib[][20]={
"lios","liala",//adj
"etr","etra",//n
"initis","inites"//ver
};
char s[1000050];
bool cmp(int i)
{
    int n=strlen(s),m=strlen(lib[i]);
    if(n<m)return 0;
    else return strcmp(s+n-m,lib[i])==0;
}
bool ok(char s[])
{
    for(int i=0;i<6;i++)
        if(cmp(i))
            return 1;
    return 0;
}
int _sex(char s[])
{
    for(int i=0;i<6;i++)
        if(cmp(i))return i%2+1;
    return 0;
}
bool is_adj(char s[])
{
    for(int i=0;i<2;i++)
        if(cmp(i))return 1;
    return 0;
}
bool is_n(char s[])
{
    for(int i=2;i<4;i++)
        if(cmp(i))return 1;
    return 0;
}
bool is_ver(char s[])
{
    for(int i=4;i<6;i++)
        if(cmp(i))return 1;
    return 0;
}
int main()
{
    int sex=-1;
    int adj=0,n=0,ver=0;
    int cnt=0;
    scanf("%s",s);
    if(ok(s))
    {
        int f=0;
        sex=_sex(s);
        if(is_adj(s));
        else if(is_n(s))adj=1,n=1;
        else
        {
            f=1;
        }
        while(~scanf("%s",s))
        {
            if(f)
            {
                printf("NO\n");
                return 0;
            }
            cnt++;
            if(ok(s))
            {
                if(sex!=_sex(s))
                {
                    printf("NO\n");
                    return 0;
                }
                if(adj==0)
                {
                    if(is_adj(s));
                    else if(is_n(s))
                    {
                        adj=1;
                        n=1;
                    }
                    else
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
                else
                {
                    if(n==0)
                    {
                        if(is_n(s))adj=1,n=1;
                        else
                        {
                            printf("NO\n");
                            return 0;
                        }
                    }
                    else
                    {
                        if(is_ver(s))
                        {
                            adj=1,n=1;
                        }
                        else
                        {
                            printf("NO\n");
                            return 0;
                        }
                    }
                }
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
        if(cnt==0)
        {
            printf("YES\n");
        }
        else
        {
            if(n==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    else
    {
        printf("NO\n");
        return 0;
    }
	return 0;
}
