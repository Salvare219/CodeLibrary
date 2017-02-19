#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


vector<pair<int,int> > gra[30];
char lib[1005][30];
int ind[1005],in[30],out[30];
int c[30];
int ans[10005],h;
bool cmp(int a,int b)
{
    return (strcmp(lib[b],lib[a])==-1)?0:1;
}
void eur(int s)
{
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i].second<5555)
        {
            gra[s][i].second+=10000;
            eur(gra[s][i].first);
        }
    ans[h++]=s;
}
void dfs(int s)
{
    if(s==0) return;
    int x=ans[s],y;
    for(int i=0;i<gra[x].size();i++)
    {
        if(gra[x][i].first==ans[s-1] && gra[x][i].second)
        {
            if(s!=1) printf("%s.",lib[gra[x][i].second-10000]);
            else printf("%s\n",lib[gra[x][i].second-10000]);
            gra[x][i].second=0;
            dfs(s-1);
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int m;
        scanf("%d",&m);
        for(int i=0;i<26;i++)
            gra[i].clear();
        for(int i=0;i<m;i++)
            scanf("%s",lib[i]),ind[i]=i;
        sort(ind,ind+m,cmp);
        int len,j;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=0;i<m;i++)
        {
            j=ind[i];
            len=strlen(lib[j])-1;
            gra[lib[j][0]-'a'].push_back(make_pair(lib[j][len]-'a',j));
            in[lib[j][len]-'a']++;out[lib[j][0]-'a']++;
        }
        int ty=0,fa=0;
        for(int i=0;i<26;i++)
        {
            if(abs(in[i]-out[i])>1)
            {
                ty=2;
                break;
            }
            else if(abs(in[i]-out[i])==1) ty=1,c[fa++]=i;
        }
        if(fa>2) ty=2;
        if(ty==0)
        {
            h=0;
            eur(lib[ind[0]][0]-'a');
            if(h-1!=m) printf("***\n");
            else dfs(h-1);

        }
        else if(ty==1)
        {
            int s=c[0];
            if(in[c[0]]-out[c[0]]>0) s=c[1];
            h=0;
            eur(s);
            if(h-1!=m) printf("***\n");
            else dfs(h-1);
        }
        else printf("***\n");
    }
	return 0;
}
