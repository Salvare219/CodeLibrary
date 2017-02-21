#include<bits/stdc++.h>
using namespace std;


pair<int,pair<int,int> >p[300050];
int main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        p[i]={x,{y,i}};
    }
    int ans=-1;
    sort(p,p+n);
    priority_queue<pair<int,int> >q;
    for(int i=0;i<n;i++)
    {
        if(q.size()<k)q.push({-p[i].second.first,p[i].second.second});
        else
        {
            if(-q.top().first<p[i].second.first)
            {
                q.pop();
                q.push({-p[i].second.first,p[i].second.second});
            }
        }
        if(q.size()==k)
            ans=max(ans,max(0,-q.top().first-p[i].first+1));
    }
    while(!q.empty())q.pop();
    int ans2=-1;
    for(int i=0;i<n;i++)
    {
        if(q.size()<k)q.push({-p[i].second.first,p[i].second.second});
        else
        {
            if(-q.top().first<p[i].second.first)
            {
                q.pop();
                q.push({-p[i].second.first,p[i].second.second});
            }
        }
        if(q.size()==k)
            ans2=max(ans2,max(0,-q.top().first-p[i].first+1));
        if(ans2==ans)
        {
            printf("%d\n",ans);
            for(int i=0;i<k;i++)
                printf("%d ",q.top().second+1),q.pop();
            break;
        }
    }
	return 0;
}

