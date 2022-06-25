class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(end-1>=0 && nums[end-1]==target)
        {
            end=end-1;
        }
        else end=-1;
        int start = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
        if(start>=nums.size() || nums[start]!=target) start=-1;
        return {start,end};
    }
};