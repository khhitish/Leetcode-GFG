class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int currsum=0;
        for(int i=0;i<nums.size();i++)
        {
            currsum+=nums[i];
            int prefsum=currsum;
            int suffsum= sum - currsum + nums[i];
            if(prefsum==suffsum) return i;
        }
        return -1;
    }
};