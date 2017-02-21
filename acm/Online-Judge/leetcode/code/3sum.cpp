class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num)
    {
        vector<vector<int> > ans;
        sort(num.begin(),num.end());
        int n=num.size(),l1=-12314312;
        for(int i=0;i<n;i++)
            if(num[i]!=l1)
            {
                l1=num[i];
                int p=n-1,l2=-12314312;
                for(int j=i+1;j<p;j++)
                    if(num[j]!=l2)
                    {
                        l2=num[j];
                        while(p>j&&num[p]+num[j]+num[i]>0)
                            p--;
                        if(p>j&&num[p]+num[j]+num[i]==0)
                        {
                            vector<int>t;
                            t.push_back(num[i]);
                            t.push_back(num[j]);
                            t.push_back(num[p]);
                            ans.push_back(t);
                        }
                    }
            }
        return ans;
    }
};