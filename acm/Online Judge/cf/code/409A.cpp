#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    char s1[20],s2[20];
    scanf("%s%s",s1,s2);
    int sb=strlen(s1)/2,a=0,b=0;
    for(int i=0;i<sb;i++)
    {
        int t1,t2;
        if(s1[2*i]=='8'&&s1[2*i+1]=='<')t1=1;
        if(s1[2*i]=='('&&s1[2*i+1]==')')t1=2;
        if(s1[2*i]=='['&&s1[2*i+1]==']')t1=3;
        if(s2[2*i]=='8'&&s2[2*i+1]=='<')t2=1;
        if(s2[2*i]=='('&&s2[2*i+1]==')')t2=2;
        if(s2[2*i]=='['&&s2[2*i+1]==']')t2=3;
        if(t1==t2);
        else
        {
            if(t1==1&&t2==2)b++;
            if(t1==1&&t2==3)a++;
            if(t1==2&&t2==3)b++;
            if(t1==2&&t2==1)a++;
            if(t1==3&&t2==1)b++;
            if(t1==3&&t2==2)a++;
        }
    }
    if(a==b)puts("TIE");
    else puts(a>b?"TEAM 1 WINS":"TEAM 2 WINS");
    return 0;
}
