class Solution
{
    public:
        int find(vector<int>& a,int n,vector<int>& b,int m,int k)
        {
            int l=k-m-1,r=k-1,m1,m2;
            if(m==0||b[0]>=a[r])return a[r];
            while(r>l)
            {
                m1=(l+r)>>1;
                m2=k-m1-1;
                if(a[m1]>b[m2])r=m1;
                else l=m1+1;
            }
            return max(a[r-1],b[k-r-1]);
        }
        double findMedianSortedArrays(vector<int>& a, vector<int>& b)
        {
            int n=a.size(),m=b.size();
            int s1=(n+m)/2,s2=(n+m)/2+1;
            if(n<m)swap(a,b),swap(n,m);
            a.push_back(1<<30);b.push_back(1<<30);
            n++;m++;
            if((n+m)&1)
                return find(a,n,b,m,s2);
            else
                return (find(a,n,b,m,s1)+find(a,n,b,m,s2))*0.5;
        }
};