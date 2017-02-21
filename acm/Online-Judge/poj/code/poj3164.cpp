#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;



struct point

{

    int x,y;

    double w;

}e[10005];

int nn,mm;

double in[105];

int vis[105],p[105],id[105];

double Minimum_Arborescence(int root)

{

    double ans=0;

    int cnt,nod=nn,x,y;

    while(1)

    {

        for(int i=1;i<=nod;i++)in[i]=0x3fffffff;

        for(int i=0;i<mm;i++)

            if(in[e[i].y]>e[i].w&&e[i].x!=e[i].y)

            {

                in[e[i].y]=e[i].w;

                p[e[i].y]=e[i].x;

            }

        in[root]=0;

        for(int i=1;i<=nod;i++)

            if(in[i]==0x3fffffff)return -1;

        cnt=1;

        for(int i=1;i<=nod;i++)

            id[i]=-1,vis[i]=-1;

        for(int i=1;i<=nod;i++)

        {

            ans+=in[i];

            x=i;

            while(vis[x]!=i && id[x]==-1 && x!=root)

                vis[x]=i,x=p[x];

            if(x!=root && id[x]==-1)

            {

                for(y=p[x];x!=y;y=p[y])

                    id[y]=cnt;

                id[x]=cnt++;

            }

        }

        if(cnt==1) return ans;

        for(int i=1;i<=nod;i++)

            if(id[i]==-1)id[i]=cnt++;

        for(int i=0;i<mm;i++)

        {

            y=e[i].y;

            e[i].x=id[e[i].x];

            e[i].y=id[e[i].y];

            if(e[i].x!=e[i].y) e[i].w-=in[y];

        }

        nod=cnt-1;

        root=id[root];

    }

}

struct pp

{

    double x,y;

}po[105];

double dis(pp a,pp b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

int main()

{

    while(scanf("%d%d", &nn, &mm) != EOF)

    {

        for(int i = 1; i <= nn; i++)

           scanf("%lf%lf", &po[i].x, &po[i].y);

        for(int i = 0; i < mm; i++)

        {

            scanf("%d%d", &e[i].x, &e[i].y);

            e[i].w = dis(po[e[i].x], po[e[i].y]);

        }

        double ans = Minimum_Arborescence(1);

        if(ans == -1) printf("poor snoopy\n");

        else printf("%.2f\n", ans);

    }

    return 0;

}

