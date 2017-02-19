#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;





vector<int>gra[1005];

vector<int>bri[2];

bool vis[1005];

int low[1005],scc[1005];

int sta[1005],sk;

bool cut[1005];

int cnt,timer,root;

void dfs(int s,int fa)

{

	int temp=low[s]=++timer,to,sz=0;

	bool flag=vis[s]=1;sta[sk++]=s;

	for(int i=0;i<gra[s].size();i++)

		if((to=gra[s][i])==fa&&flag) flag=0;

		else

        {

            if(vis[to])low[s]=min(low[to],low[s]);

            else

            {

                dfs(to,s);sz++;

                low[s]=min(low[to],low[s]);



                if(low[to]>=temp)

                {

                    if(s!=root)cut[s]=1;

                    else if(sz>1)cut[s]=1;

                }



                if(low[to]>temp)

                {

                    bri[0].push_back(s);

                    bri[1].push_back(to);

                }



            }

        }



    if(low[s]==temp)

    {

        do to=sta[--sk],scc[to]=cnt;

        while(sta[sk]!=s);

        cnt++;

    }



}



int deg[1005];

int main()

{

    int n,m;

    while(~scanf("%d%d",&n,&m))

    {

        int x,y;

        for(int i=1;i<=n;i++)gra[i].clear(),vis[i]=deg[i]=0;

        for(int i=0;i<m;i++)

        {

            scanf("%d%d",&x,&y);

            gra[x].push_back(y);

            gra[y].push_back(x);

        }

        cnt=1;timer=0;

        memset(vis,0,sizeof(vis));

        dfs(1,0);

        for(int i=1;i<=n;i++)

            for(int j=0;j<gra[i].size();j++)

                if(scc[i]!=scc[x=gra[i][j]])

                    deg[scc[i]]++,deg[scc[x]]++;

        int ans=0;

        for(int i=1;i<cnt;i++)

            if(deg[i]==2)ans++;

        printf("%d\n",(ans+1)/2);

    }

    return 0;

}

