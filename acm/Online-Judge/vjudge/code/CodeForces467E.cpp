#include <bits/stdc++.h>
using namespace std;


int a[500050];
int sa[500050];
int las[500050];
map<int,pair<int,int> >mp;
map<int,int>mp2;
vector<int>ans;
int ok(int f)
{
    if(mp.size()==0)return -1;
    int x=las[a[f]],y=f;
    map<int,pair<int,int> >::iterator it=mp.lower_bound(x);
    if(it==mp.begin())return -1;
    it--;
    pair<int,int>z=it->second;
    if(z.first>x)return z.second;
    else return -1;
}
void updat(int l,int r)
{
    if(mp.size())
    {
        map<int,pair<int,int> >::iterator it=mp.upper_bound(l),it2;
        if(it!=mp.begin())
        {
            it--;
            if((it->second.first)>=r)return;
            it++;
        }
        it2=it;
        while(it2!=mp.end()&&it2->second.first<=r)
            it2++;
        mp.erase(it,it2);
        mp[l]=make_pair(r,a[l]);
    }
    else mp[l]=make_pair(r,a[l]);

    //putchar(10);
    //for(map<int,pair<int,int> >::iterator it=mp.begin();it!=mp.end();it++)
    //    printf("**%d %d\n",it->first,it->second.first);
    //putchar(10);

}
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),sa[i]=a[i];
    sort(sa,sa+n);
    int k=unique(sa,sa+n)-sa;
    for(int i=0;i<n;i++)
        a[i]=lower_bound(sa,sa+n,a[i])-sa;
    memset(las,-1,sizeof(las));
    int l=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        if(las[a[i]]<l)las[a[i]]=-1;
        else
        {
            int f=ok(i);
            if(f==-1)
            {
                if(mp2[a[i]]>=3)
                {
                    c=1;
                    l=i+1;
                    mp.clear();
                    mp2.clear();
                    ans.push_back(a[i]);
                    ans.push_back(a[i]);
                    ans.push_back(a[i]);
                    ans.push_back(a[i]);
                }
                else
                    updat(las[a[i]],i);
            }
            else
            {
                c=1;
                l=i+1;
                mp.clear();
                mp2.clear();
                ans.push_back(f);
                ans.push_back(a[i]);
                ans.push_back(f);
                ans.push_back(a[i]);
            }
        }
        if(c==0)
        {
            las[a[i]]=i;
            mp2[a[i]]++;
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",sa[ans[i]]);putchar(10);
    return 0;
}
