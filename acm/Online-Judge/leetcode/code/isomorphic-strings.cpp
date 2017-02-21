
bool v[2000000];
int p[2000000];

class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(v[i]==0)p[ans++]=i;
            for(int j=0;j<ans&&p[j]*i<n;j++)
            {
                v[i*p[j]]=1;
                if(i%p[j]==0)
                    break;
            }
        }
        return ans;
    }
};