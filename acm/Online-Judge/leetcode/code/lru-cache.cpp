/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
long long stad(long long x,long long y)
{
    long long g=__gcd(abs(x),abs(y));
    if(y<0)y*=-1,x*=-1;
    x/=g;y/=g;
    return (x<<31)|y;
}
class Solution {
public:
    int maxPoints(vector<Point>& p) {
        int n=p.size(),fin=0;
        unordered_map<long long,int>mp;
        for(int i=0;i<n;i++)
        {
            int same=0,ans=0;
            mp.clear();
            for(int j=0;j<n;j++)
                if(p[i].x==p[j].x&&p[i].y==p[j].y)same++;
                else ans=max(ans,(++mp[stad(p[j].x-p[i].x,p[j].y-p[i].y)]));
            fin=max(fin,ans+same);
        }
        return fin;
    }
};