int s[100000],d[100000];
class Solution {
public:
    int maximumGap(vector<int>& a) {
        int n=a.size(),x=0x7fffffff,y=-0x7fffffff;
        if(n<2)return 0;
        for(int i=0;i<n;i++)
            x=min(x,a[i]),y=max(y,a[i]),s[i]=0x7fffffff,d[i]=-0x7fffffff;
        int f=(y-x+n)/(n-1);
        for(int i=0;i<n;i++)
        {
            int k=(a[i]-x)/f;
            s[k]=min(s[k],a[i]);
            d[k]=max(d[k],a[i]);
        }
        int ans=0,las=0,has=0;
        for(int i=0;i<n-1;i++)
        {
            if(d[i]>=s[i])
            {
                
                ans=max(ans,d[i]-s[i]);
                if(has)ans=max(ans,s[i]-las);
                has=1;
                las=d[i];
            }
        }
        return ans;
    }
};