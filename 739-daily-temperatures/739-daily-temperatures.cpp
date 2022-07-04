class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> ans(n);
        
        // stack based standard approach
        // stack<int> s;
        // for(int i=n-1;i>=0;i--)
        // {
        //     while(!s.empty() && t[s.top()]<=t[i])s.pop();
        //     if(s.empty()) ans[i]=0;
        //     else ans[i]=s.top()-i;
        //     s.push(i);
        // }
        // return ans;
        
        //using ans array for information O(1) space, O(n) time see solution
        int hottest=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(t[i]>=hottest) ans[i]=0;
            else
            {
                int check = i+1;
                while(t[check]<=t[i])
                {
                    check+=ans[check];
                }
                ans[i] = (check-i);
            }
            hottest=max(hottest,t[i]);
        }
        return ans;
    }
};