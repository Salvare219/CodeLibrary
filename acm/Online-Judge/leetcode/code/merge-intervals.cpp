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
    vector<Interval> merge(vector<Interval>& f) {
        vector<pair<int,int>>c;
        int n=f.size();
        if(n==0)return f;
        for(int i=0;i<n;i++)
            c.push_back(make_pair(f[i].start,f[i].end));
        f.clear();
        sort(c.begin(),c.end());
        int x=c[0].first,y=c[0].second;
        for(int i=0;i<n;i++)
            if(y<c[i].first)
            {
                f.push_back(Interval(x,y));
                x=c[i].first;
                y=c[i].second;
            }
            else 
                y=max(y,c[i].second);
        f.push_back(Interval(x,y));
        return f;
    }
};