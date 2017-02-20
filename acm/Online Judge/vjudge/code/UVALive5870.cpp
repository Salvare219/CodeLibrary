#include<bits/stdc++.h>
using namespace std;


char s[200];
char a[20][2000];
void draw(int x,int y,int &f)
{
    int d=1;
    if(x>y)d=-1;
    while(fabs(x-y)>1)
    {
        x+=d;
        for(int i=10-x;i<=10;i++)
            a[i][f]='+';
        for(int i=10-x-1;i>=0;i--)
            a[i][f]='*';
        f++;
    }
    for(int i=10-y;i<=10;i++)
        a[i][f]='+';
    for(int i=10-y-1;i>=0;i--)
        a[i][f]='*';
    f++;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s),las=s[0],fin=0,f=0;
        for(int i=0;i<n;i++)
            draw(las-'0',s[i]-'0',f),las=s[i],fin=max(fin,(int)s[i]-'0');
        for(int i=0;i<20;i++)
            a[i][f]=0;
        for(int i=10-fin;i<10;i++)
            puts(a[i]);
    }
    return 0;
}
