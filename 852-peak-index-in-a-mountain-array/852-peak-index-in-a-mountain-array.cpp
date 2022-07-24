class Solution
{
    public:
        int peakIndexInMountainArray(vector<int> &nums)
        {
            // int n = nums.size();
            // if (n == 1) return 0;
            // int low = 0, high = n - 1;
            // while (low <= high)
            // {
            //     int mid = low + (high - low) / 2;
            //     if (mid > 0 && mid < n - 1)
            //     {
            //         if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            //         else
            //         {
            //             if (nums[mid + 1] > nums[mid - 1]) low = mid + 1;
            //             else high = mid - 1;
            //         }
            //     }
            //     else
            //     {
            //         if (mid == 0)
            //         {
            //             if (nums[mid] > nums[mid + 1]) return mid;
            //             else low = mid + 1;
            //         }
            //         else
            //         {
            //             if (nums[mid] > nums[mid - 1]) return mid;
            //             else high = mid - 1;
            //         }
            //     }
            // }
            // return -1;
            int n = nums.size();
            int low = 0, high = n-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                int left_val;
                if(mid-1 >=0)
                {
                    left_val = nums[mid-1];
                }
                else left_val = INT_MIN;
                int right_val;
                if(mid+1<n)
                {
                    right_val = nums[mid+1];
                }
                else right_val = INT_MIN;
                if(left_val<nums[mid] && nums[mid]<right_val)
                {
                    low = mid+1;
                }
                else if(left_val>nums[mid] && nums[mid]>right_val)
                {
                    high = mid-1;
                }
                else
                {
                    return mid;
                }
            }
            return -1;

        }
};