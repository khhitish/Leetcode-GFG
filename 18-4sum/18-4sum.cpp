class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
            int n = nums.size();
            if (n < 4) return {};
            sort(nums.begin(), nums.end());
            vector<vector < int>> ans;
            int j = 0;
            while (j < n - 3)
            {
                int i = j + 1;
                while (i < n - 2)
                {
                    int left = i + 1, right = n - 1;
                    long long req = (long long)target - nums[j] - nums[i];
                    while (left < right)
                    {
                        if (nums[left] + nums[right] > req) right--;
                        else if (nums[left] + nums[right] < req) left++;
                        else
                        {
                            ans.push_back({ nums[j],
                                nums[i],
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
                int temp = nums[j];
                while (j < n - 3 && nums[j] == temp) j++;
            }
            return ans;
        }
};