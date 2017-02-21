#include <bits/stdc++.h>
using namespace std;



char p[20][20],t[20][20];
char s1[20],s2[20];
int ans,l1,l2,n;
void dfs(char s[],int l,int d)
{
    if(l==l2)
    {
        if(strcmp(s,s2)==0)ans=min(ans,d);
    }
    else if(l<l2)
    {
        char f[200];
        for(int i=0;i<n;i++)
        {
            int h=strlen(p[i]),h2=strlen(t[i]),k=0;
            for(int j=0;j<l;j++)
            {
                char c=s[j+h];
                s[j+h]=0;
                if(strcmp(s+j,p[i])==0)
                {
                    s[j+h]=c;
                    for(int z=0;z<h2;z++)
                        f[k++]=t[i][z];
                    j+=h-1;
                }
                else s[j+h]=c,f[k++]=s[j];
            }
            f[k]=0;
            if(l<k)dfs(f,k,d+1);
        }
    }
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {

        for(int i=0;i<n;i++)
            scanf("%s%s",p[i],t[i]);
        scanf("%s%s",s1,s2);
        l1=strlen(s1);
        l2=strlen(s2);
        ans=100000;dfs(s1,l1,0);
        if(ans==100000)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
