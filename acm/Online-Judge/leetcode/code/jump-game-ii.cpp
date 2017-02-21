class Solution {
public:
    int find(vector<int>&a,int l,int r,int k)
    {
        int mid;
        if(a[r]<k)return -1;
        while(r>l)
        {
            mid=(r+l)>>1;
            if(a[mid]>=k)r=mid;
            else l=mid+1;
        }
        return a[r]==k?r:-1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)return -1;
        int l=0,r=n-1,mid;
        if(nums[0]<nums[n-1])return find(nums,0,n-1,target);
        while(r>l)
        {
            mid=(l+r+1)>>1;
            if(nums[mid]>nums[n-1])l=mid;
            else r=mid-1;
        }
        if(target>nums[n-1])return find(nums,0,l,target);
        else return find(nums,l+1,n-1,target);
    }
};