class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,l=1, n=nums.size();
        for(i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[l]=nums[i];
                l++;
            }
        }
        return l;
    }
};