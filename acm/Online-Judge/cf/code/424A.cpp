#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[100000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d%s",&n,s);
    int a=0,b=0;
    for(int i=0;i<n;i++)
        if(s[i]=='x')a++;
        else b++;
    if(a>b)
    {
        int dif=a-b;
        for(int i=0;dif;i++)
            if(s[i]=='x')s[i]='X',dif-=2;
    }
    else
    {
        int dif=b-a;
        for(int i=0;dif;i++)
            if(s[i]=='X')s[i]='x',dif-=2;
    }
    printf("%d\n",abs(a-b)/2);
    puts(s);
    return 0;
}
