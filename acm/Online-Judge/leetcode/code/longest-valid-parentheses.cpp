class Solution {
public:
    vector<pair<int,int>>ans;
    void in(int x,int y,int &las)
    {
        printf("%d %d %d\n",x,y,las);
        if(x<las)return;
        ans.push_back(make_pair(las,y));
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& c) {
        int n=c.size();
        ans.clear();
        if(n==0)return ans;
        vector<pair<int,pair<int,int>>>cv;
        priority_queue<pair<int,int>> s;
        for(int i=0;i<n;i++)
            cv.push_back(make_pair(c[i][0],make_pair(c[i][1],-c[i][2])));
        sort(cv.begin(),cv.end());
        int las=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&s.top().second<cv[i].first)
            {
                las=max(las,s.top().second);
                s.pop();
                if(s.empty())in(las,0,las);
                else in(s.top().second,s.top().first,las);
            }
            las=max(las,cv[i].first);
            s.push(make_pair(-cv[i].second.second,cv[i].second.first));
            in(cv[i].first,s.top().first,las);
        }
        while(!s.empty())
        {
            las=max(las,s.top().second);
            s.pop();
            if(s.empty())in(las,0,las);
            else in(s.top().second,s.top().first,las);
        }
        vector<pair<int,int>>ein;
        ein.push_back(ans[0]);
        for(int i=1;i<ans.size();i++)
            if(ein[ein.size()-1].second==ans[i].second);
            else 
            {
                if(ein[ein.size()-1].first==ans[i].first)ein[ein.size()-1]=ans[i];
                else ein.push_back(ans[i]);
            }
        return ein;
    }
};