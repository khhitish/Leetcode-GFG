class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        for(;j<nums.size();j++)
        {
            if(nums[j]!=nums[j-1])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};