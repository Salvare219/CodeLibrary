/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
pair<int,int>stad(int x,int y)
{
    int g=__gcd(x,y);
    if(y<0)x*=-1,y*=-1;
    return make_pair(x/g,y/g);
}
class Solution {
public:
    int maxPoints(vector<Point>& p) {
        int n=p.size(),fin=0;
        vector<pair<int,int> >c;
        for(int i=0;i<n;i++)
        {
            int same=0;
            c.clear();
            for(int j=0;j<n;j++)
                if(p[i].x==p[j].x&&p[i].y==p[j].y)same++;
                else c.push_back(stad(p[j].x-p[i].x,p[j].y-p[i].y));
            sort(c.begin(),c.end());
            int now=min((int)c.size(),1),ans=now;
            for(int j=1;j<c.size();j++)
                if(c[j]==c[j-1])ans=max(ans,++now);
                else now=1;
            fin=max(fin,ans+same);
        }
        return fin;
    }
};