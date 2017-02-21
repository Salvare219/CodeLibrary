#include<bits/stdc++.h>
using namespace std;


set<pair<int,int> >st;
vector<vector<int> >dep;
int p[100005];
bool v[100005];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",p+i);
    int fm=n+12,ind=-1;
    for(int i=1;i<=n;i++)
        if(v[i]==0)
        {
            int x=i;
            vector<int>f;
            while(v[x]==0)
            {
                f.push_back(x);
                v[x]=1;
                x=p[x];
            }
            dep.push_back(f);
            if(f.size()<fm)
            {
                fm=f.size();
                ind=dep.size()-1;
            }
        }
    if(fm>=3)puts("NO");
    else
    {
        if(fm==2)
        {
            int ff=0;
            for(int i=0;i<dep.size();i++)
                if(dep[i].size()%2)
                    ff=1;
            if(ff)
                puts("NO");
            else
            {
                puts("YES");
                printf("%d %d\n",dep[ind][0],dep[ind][1]);
                for(int i=0;i<dep.size();i++)
                    if(i!=ind)
                    {
                        for(int j=0;j<dep[i].size();j++)
                            if(j&1)
                                printf("%d %d\n",dep[ind][1],dep[i][j]);
                            else
                                printf("%d %d\n",dep[ind][0],dep[i][j]);
                    }
            }
        }
        else
        {
            puts("YES");
            for(int i=0;i<dep.size();i++)
                if(i!=ind)
                {
                    for(int j=0;j<dep[i].size();j++)
                        printf("%d %d\n",dep[ind][0],dep[i][j]);
                }
        }
    }
    return 0;
}
