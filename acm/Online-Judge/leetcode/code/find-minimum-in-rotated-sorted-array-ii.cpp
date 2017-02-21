class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),c=nums[0];
        for(int i=0;i<n;i++)
            c=min(c,nums[i]);
        return c;
    }
};