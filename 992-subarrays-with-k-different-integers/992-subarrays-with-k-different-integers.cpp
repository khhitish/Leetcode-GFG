class Solution {
private:
    int atmostk(int k, vector<int>& nums)
    {
        int ans=0, n=nums.size();
        unordered_map<int,int> m;
        int left=0, right=0;
        while(right<n)
        {
            m[nums[right]]++;
            if(m.size()>k)
            {
                while(m.size()>k)
                {
                    m[nums[left]]--;
                    if(m[nums[left]]==0)m.erase(nums[left]);
                    ans+=(right-left);
                    left++;
                }
            }
            right++;
        }
        ans+=(right-left)*(right-left+1)/2;
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = atmostk(k,nums) - atmostk(k-1,nums);
        return ans;
    }
};