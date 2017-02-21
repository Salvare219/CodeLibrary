pair<int,int> q[100000];
int tail,front;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        tail=front=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            while(tail<front&&q[front-1].first<nums[i])front--;
            q[front++]=make_pair(nums[i],i);
            while(tail<front&&q[tail].second<i-k+1)tail++;
            if(i>=k-1)ans.push_back(q[tail].first);
        }
        return ans;
    }
};