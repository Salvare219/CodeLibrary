#include<bits/stdc++.h>
using namespace std;



char s[10050];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("acm.in","r",stdin);
    freopen("acm.out","w",stdout);
    int n,m,k=0;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        s[k++]='(';
        s[k++]='1';
        s[k++]='0';
        for(int j=0;j<x;j++)
            s[k++]='-',s[k++]='1';
        s[k++]=')';
        s[k++]='*';
    }
    s[k]=0;
    printf("%s",s);
    printf("(10-1)=");
    printf("%s",s);
    puts("(1000000-1)");
    return 0;
}
