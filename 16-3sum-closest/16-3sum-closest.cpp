class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int mindiff = INT_MAX, ans;
            for (int i = 0; i < n - 2; i++)
            {
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(target - sum) < mindiff)
                    {
                        mindiff = abs(target - sum);
                        ans = sum;
                    }
                    if (sum > target) k--;
                    else if (sum < target) j++;
                    else return ans;
                }
            }
            return ans;
        }
};