#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char str[200500];
char stack[200500];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s",str);
    int ti=0,k=0,ha=0;
    for(int i=0;str[i];i++)
    {
        if(k==0) stack[k++]=str[i],ti=1;
        else
        {
            if(stack[k-1]!=str[i])
            {
                stack[k++]=str[i];
                if(ti==2) ha=1;
                else ha=0;
                ti=1;
            }
            else
            {
                if(ti!=2)
                {
                    if(ha==0)
                    {
                        stack[k++]=str[i];
                        ti++;
                    }
                }
            }
        }
    }
    stack[k]=0;
    puts(stack);
    return 0;
}
