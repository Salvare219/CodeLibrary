
class Solution { 
public:
    int longestValidParentheses(string g) {
        stack<int>s;
        int ans=0,pre=0;
        for(auto x:g)
            if(x=='(')
                s.push(0);
            else 
            {
                if(s.empty())pre=0;
                else 
                {
                    int x=s.top()+2;
                    s.pop();
                    if(s.empty())pre+=x;
                    else x+=s.top(),s.pop(),s.push(x);
                    if(s.empty())ans=max(ans,pre);
                    else ans=max(ans,x);
                }
            }
        return ans;
    }
};