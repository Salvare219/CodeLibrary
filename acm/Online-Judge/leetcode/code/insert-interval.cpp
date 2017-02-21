/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& c, Interval s) {
        int n=c.size();
        vector<Interval>ans;
        if(n==0)return ans.push_back(s),ans;
        int x=s.start,y=s.end,g=1;
        if(c[0].start>y)return c.insert(c.begin(),s),c;
        for(int i=0;i<n;i++)
        {
            int x1=c[i].start,y1=c[i].end;
            if(x<=y1&&y>=x1)x=min(x,x1),y=max(y,y1);
            else 
            {
                if(g&&y<x1)g=0,ans.push_back(Interval(x,y));
                ans.push_back(c[i]);
            }
        }
        if(g)ans.push_back(Interval(x,y));
        return ans;
    }
};