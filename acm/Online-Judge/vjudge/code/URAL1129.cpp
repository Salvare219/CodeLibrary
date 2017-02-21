#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>gra[105],z;
int sz[105];
int v[105][105];
int c[105][105];
bool sb[105];
void eur(int s)
{
    sb[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(v[s][gra[s][i]])
        {
            if(c[s][gra[s][i]]==0)
                c[s][gra[s][i]]=1,c[gra[s][i]][s]=2;
            v[s][gra[s][i]]--;
            v[gra[s][i]][s]--;
            eur(gra[s][i]);
        }
}
int main()
{
    int n,k=0,x,y;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);sz[i]=x;
        for(int j=0;j<x;j++)
        {
            scanf("%d",&y);
            gra[i].push_back(y);
            v[i][y]++;
        }
    }
    for(int i=1;i<=n;i++)
        if(sz[i]&1)z.push_back(i);
    {
        for(int i=0;i<z.size();i+=2)
        {
            gra[z[i]].push_back(z[i+1]);
            gra[z[i+1]].push_back(z[i]);
            v[z[i]][z[i+1]]++;
            v[z[i+1]][z[i]]++;
        }
        for(int i=1;i<=n;i++)
            if(sb[i]==0)eur(i);
        int p=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<sz[i];j++)
                printf("%c%c",c[i][gra[i][j]]==1?'G':'Y',j==sz[i]-1?10:' ');
        }
    }
    return 0;
}