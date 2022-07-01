class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0, n=nums.size();
        while(i<n)
        {
            int correct = nums[i]-1;
            if(nums[correct]!=nums[i])
            {
                swap(nums[correct], nums[i]);
            }
            else
            {
                i++;
            }
        }
        return nums.back();
    }
};