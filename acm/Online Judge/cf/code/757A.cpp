#include<bits/stdc++.h>
using namespace std;


char s[200000];
//  Bulbasaur
char lib[]="Bulbasr";
int mp[2222];
int main()
{
    //freopen("2.txt","w",stdout);
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
        mp[s[i]]++;
    int ans=100000;
    for(int i=0;lib[i];i++)
        if(lib[i]=='a'||lib[i]=='u')
            ans=min(ans,mp[lib[i]]/2);
        else
            ans=min(ans,mp[lib[i]]);
    printf("%d\n",ans);
    return 0;
}
