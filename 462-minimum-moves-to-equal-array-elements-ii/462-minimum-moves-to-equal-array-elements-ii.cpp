class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int y = nums[nums.size()/2];
        for(auto&x : nums)
        {
            ans+=abs(x-y);
        }
        return ans;
    }
};