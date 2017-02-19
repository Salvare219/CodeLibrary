#include<bits/stdc++.h>
using namespace std;


int main()
{
    int x,y,x1,y1;
    scanf("%d%d%d%d",&x,&y,&x1,&y1);
    if(x==0&&y==0)puts("Polycarp");
    else if(x1==0&&y1==0)puts("Vasiliy");
    else
    {
        int s1,s2;
        if(x+y<=max(x1,y1))puts("Polycarp");
        else
        {
            s2=max(x1-x,y1-y);
            if(s2<0)puts("Vasiliy");
            else
            {
                s1=abs(x-(x1-s2))+abs(y-(y1-s2));
                puts(s1<=s2?"Polycarp":"Vasiliy");
            }
        }
    }
    return 0;
}
