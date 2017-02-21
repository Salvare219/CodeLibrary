class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <= 2) return ans;
        sort(nums.begin(), nums.end());
        int flag = 0;
        int cnt = 0;
        vector<int> temp(3, 0); 
        int n=nums.size();
        for(int i = 0; i < n; i++) 
        if(i==0 || nums[i]!=nums[i-1]){
            for(int j = i+1, k = n-1; j < k;) {
                cnt++;
                if(nums[i]+nums[j]+nums[k] == 0) {
                    if(flag && temp[0] == nums[i] && temp[1] == nums[j] && temp[2] == nums[k]) {
                        j++;
                        k--;
                        continue;
                    }
                    flag = 1;
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    ans.push_back(temp);
                    j++;
                    k--;
                    
                }
                else if(nums[i]+nums[j]+nums[k] < 0)
                    j++;
                else k--;
            }
        }
        cout << cnt << endl;
        return ans;
    }
};