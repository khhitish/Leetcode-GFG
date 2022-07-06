class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // deque approach, maintaining a decreasing order from front to back
        deque<int> d;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!d.empty() && nums[d.back()]<=nums[i]) d.pop_back();
            d.push_back(i);
            if(i>=k-1)
            {
                while(!d.empty() && d.front()<i-k+1)d.pop_front();
                ans.push_back(nums[d.front()]);
            }
        }
        return ans;
    }
};