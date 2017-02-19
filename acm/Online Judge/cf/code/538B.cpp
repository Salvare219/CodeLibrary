#include<bits/stdc++.h>
using namespace std;


char s[555];
bool ok(int n)
{
    for(int i=0;i<n;i++)
        if(s[i]!='0')return 1;
    return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%s",&s);
    int n=strlen(s);
    vector<int>ans;
    while(ok(n))
    {
        int f=0,c=0;
        for(int i=0;i<n;i++)
            if(s[i]!='0')
            {
                s[i]--;
                c=c*10+1;
            }
            else
            {
                c*=10;
            }
        ans.push_back(c);
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);puts("");
    return 0;
}

