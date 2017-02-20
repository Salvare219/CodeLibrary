#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#include<map>
#include<string>
#include<iostream>
map<string,string>mp;
char s[10000];
int main()
{
    int n;scanf("%d\n",&n);
    string a,b;
    for(int i=0;i<n;i++)
    {
        gets(s);a=s;
        gets(s);b=s;
        mp[a]=b;
    }
    int q;scanf("%d\n",&q);
    while(q--)
    {
        gets(s);a=s;
        cout<<mp[a]<<endl;
    }
    return 0;
}
