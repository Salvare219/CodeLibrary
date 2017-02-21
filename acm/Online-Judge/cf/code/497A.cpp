#include <bits/stdc++.h>
using namespace std;


char s[1050][1050];
int d[1050];
set<pair<int,int> >h;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
        if(i)h.insert(make_pair(i-1,i));
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int f=0;
        for(set<pair<int,int> >::iterator it=h.begin();it!=h.end();it++)
        {
            int x=it->first,y=it->second;
            if(s[x][i]>s[y][i])
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cnt++;
        }
        else
        {
            for(set<pair<int,int> >::iterator it=h.begin();it!=h.end();)
            {
                int x=it->first,y=it->second;
                if(s[x][i]<s[y][i])
                {
                    set<pair<int,int> >::iterator f=it;
                    it++;
                    h.erase(f);
                }
                else it++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
