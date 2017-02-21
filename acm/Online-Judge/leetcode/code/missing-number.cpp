class Solution {
public:
    unordered_set<int> has;
    int dfs(int s)
    {
        unordered_set<int>::iterator it=has.find(s);
        if(it!=has.end())
        {
            has.erase(it);
            return 1+dfs(s-1)+dfs(s+1);
        }
        else return 0;
    }
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        has.clear();
        for(int i=0;i<n;i++)
            has.insert(nums[i]);
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dfs(nums[i]));
        return ans;
    }
};