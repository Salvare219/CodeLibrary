#include<bits/stdc++.h>
using namespace std;


char s[100000],t[100000];
int cal(char a,char b)
{
    int t=abs((a-b));
    return min(abs(t),abs(10-t));
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    scanf("%s%s",s,t);
    int ans=0;
    for(int i=0;i<n;i++)
        ans+=cal(s[i],t[i]);
    printf("%d\n",ans);
    return 0;
}

