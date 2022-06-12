class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, int> mpp;
            for (int i = 0; i < nums.size(); i++)
            {
                if (mpp.count(target - nums[i]) > 0)
                {
                    return {
                        mpp[target - nums[i]],
                        i
                    };
                }
                else
                {
                    mpp[nums[i]] = i;
                }
            }
            return { -1 };
        }
};