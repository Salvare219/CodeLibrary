class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)a[i]--;
        for(int i=0;i<n;i++)
        {
            while(a[i]!=i)
            {
                if(a[a[i]]==a[i])return a[i]+1;
                swap(a[i],a[a[i]]);
            }
        }
    }
};