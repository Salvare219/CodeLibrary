class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>pos;
        for(int i=0;i<n;i++)
            if(pos.count(nums[i])==0)
                pos[nums[i]]=i;
            else
            {
                if(i-pos[nums[i]]<=k)
                    return true;
                pos[nums[i]]=i;
            }
        return false;
    }
};