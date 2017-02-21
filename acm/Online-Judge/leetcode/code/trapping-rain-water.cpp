class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        if(n==1)return 0;
        int ans=0,to=a[0],to2=-1;
        for(int i=0;i<n;i++)
        {
            if(i>to)ans++,to=to2;
            if(to>=n-1)return ans+1;
            to2=max(to2,a[i]+i);
        }
    }
};