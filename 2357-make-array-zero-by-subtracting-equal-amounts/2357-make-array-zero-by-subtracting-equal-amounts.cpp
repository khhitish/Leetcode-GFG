class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                int temp = nums[i];
                for(int j = i;j<nums.size();j++)
                {
                    nums[j]-=temp;
                }
                count++;
            }
        }
        return count;
    }
};