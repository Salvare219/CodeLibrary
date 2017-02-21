#include<bits/stdc++.h>
using namespace std;

vector<int> v[3000];
map<char,int> lib;
bool f[55][5005];
char a[55];

int dfs(int l,int r,int d)
{
    int s=l*55+r,i,j,J,k,K,L,R;
    if(v[s].size())
        return s;
    if(l>=r)
    {
        v[s].push_back(lib[a[l]]);
        return s;
    }
    memset(f[d],0,sizeof(f[0]));
    for(i=l;i<r;i++)
    {
        L=dfs(l,i,d+1),R=dfs(i+1,r,d+1);
        J=v[L].size(),K=v[R].size();
        for(j=0;j<J;j++)
            for(k=0;k<K;k++)
                f[d][v[L][j]>=v[R][k]?v[L][j]+v[R][k]:v[R][k]-v[L][j]]=1;
    }
    for(i=0;i<=5000;i++)
        if(f[d][i])
            v[s].push_back(i);
    return s;
}

int main()
{
    int i,j,s,T=0;
    lib['I']=1;lib['V']=5;lib['X']=10;lib['L']=50;lib['C']=100;
    while(~scanf("%s",a)&&a[0]!='0')
    {
        for(i=0;i<3000;i++)
            v[i].clear();
        s=dfs(0,strlen(a)-1,0);
        printf("Case %d:",++T);
        for(i=0,j=v[s].size();i<j;i++)
            printf(" %d",v[s][i]);
        puts("");
    }
}
