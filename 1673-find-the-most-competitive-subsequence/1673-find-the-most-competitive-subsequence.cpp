class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;
        int i=0, n=nums.size();
        while(i<n)
        {
            while(!s.empty() && nums[i]<s.top())
            {
                if(s.size()-1 + n - i >=k) //means we still have enough elements to make a k sized sub
                {
                    s.pop();
                }
                else break;
            }
            if(s.size()<k)s.push(nums[i]);
            i++;
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};