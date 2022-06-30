class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int ans = -1;
            int n = nums.size();
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (mid == n - 1) return nums[mid];	// to avoid writing long edge cases when mid==n-1, we observed and directly returned
                if (mid % 2 == 0)
                {
                    if (nums[mid] == nums[mid + 1]) low = mid + 1;
                    else
                    {
                        ans = nums[mid];
                        high = mid - 1;
                    }
                }
                else
                {
                    if (nums[mid] == nums[mid + 1]) high = mid - 1;
                    else low = mid + 1;
                }
            }
            return ans;
        }
};