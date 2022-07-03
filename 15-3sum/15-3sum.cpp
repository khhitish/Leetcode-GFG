class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            int n = nums.size();
            if (n < 3) return {};
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            int i = 0;
            while (i < n - 2)
            {
                int left = i + 1, right = n - 1;
                int req = -nums[i];
                while (left < right)
                {
                    if (nums[left] + nums[right] > req) right--;
                    else if (nums[left] + nums[right] < req) left++;
                    else
                    {
                        ans.push_back({ nums[i],
                            nums[left],
                            nums[right] });
                        int temp = nums[left];
                        while (left < right && nums[left] == temp) left++;
                        temp = nums[right];
                        while (right > left && nums[right] == temp) right--;
                    }
                }
                int temp = nums[i];
                while (i < n - 2 && temp == nums[i]) i++;
            }
            return ans;
        }
};