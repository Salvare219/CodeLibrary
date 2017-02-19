#include<bits/stdc++.h>
using namespace std;


char s[50];
int ans[55555];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d%s",&n,s);
    int k=0;
    for(int j=0;j<n;j++)
    {
        int i=s[j]-'0';
        if(i<=1);
        else if(i==2||i==3||i==5||i==7)ans[k++]=i;
        else if(i==4)ans[k++]=3,ans[k++]=2,ans[k++]=2;
        else if(i==6)ans[k++]=5,ans[k++]=3;
        else if(i==8)ans[k++]=7,ans[k++]=2,ans[k++]=2,ans[k++]=2;
        else ans[k++]=7,ans[k++]=3,ans[k++]=3,ans[k++]=2;
    }
    sort(ans,ans+k);
    for(int i=k-1;i>-1;i--)
        printf("%d",ans[i]);puts("");
    return 0;
}
