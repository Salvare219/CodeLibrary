#include<bits/stdc++.h>
using namespace std;

char a[15],b[15];
int bb,i;

int main()
{
    while(scanf("%s",a)==1)
    {
        for(i=0;i<bb&&a[i];i++)
            if(a[i]!=b[i])
                break;
        bb=i;
        for(i=0;i<bb;i++)
            putchar(' ');
        puts(a);
        b[bb]=a[bb];bb++;
    }
    return 0;
}
