class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid+1<=high && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(mid-1>=low && nums[mid-1]>nums[mid]) return nums[mid];
            if(nums[low]<nums[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return min(nums[0], nums.back());
    }
};