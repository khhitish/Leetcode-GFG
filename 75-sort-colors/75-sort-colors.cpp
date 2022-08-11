class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0, ones = nums.size()-1;
        int i=0;
        while(i<=ones)
        {
            if(nums[i] == 0)
            {
                swap(nums[i++],nums[zeros++]);
            }
            else if(nums[i]==2)
            {
                swap(nums[i], nums[ones--]);
            }
            else
            {
                i++;
            }
        }
    }
};