class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int smaller = -1;
        int n = nums.size();
        for(int i = n-1;i>=1;i--)
        {
            if(nums[i] > nums[i-1])
            {
                smaller=i-1;
                break;
            }
        }
        if(smaller == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int swapwith;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i] > nums[smaller])
            {
                swapwith=i;
                break;
            }
        }
        swap(nums[smaller],nums[swapwith]);
        reverse(nums.begin() + smaller+1,nums.end());
    }
};