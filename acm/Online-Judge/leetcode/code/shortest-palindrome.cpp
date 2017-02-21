char str[500000];
int pal[500000];
class Solution {
public:
    string shortestPalindrome(string s)
    {
        int n=s.size(),k=0;
        if(n==0)return "";
        str[k++]='&';
        for(int i=0;i<n;i++)
            str[k++]=s[i],str[k++]='$';
        str[k]=0;
        int mx=0,id;
        for(int i=1;i<k;i++)
        {
            if(mx>i)pal[i]=min(mx-i,pal[2*id-i]);
            else pal[i]=1;
            while(str[i+pal[i]]==str[i-pal[i]])pal[i]++;
            if(pal[i]+i>mx)mx=pal[i]+i,id=i;
        }
        int ans=0;
        for(int i=1;i<k;i++)
            if(i-(pal[i]-1)==1)
                ans=max(ans,(i+pal[i])/2);
        string t;
        for(int i=0;i<n-ans;i++)
            t+=s[n-i-1];
        return t+s;
    }
};
