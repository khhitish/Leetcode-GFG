class Solution
{
    private:
       	// https://www.ideserve.co.in/learn/find-pivot-in-a-sorted-rotated-array
        int findpivot(vector<int> &nums, int low, int high)
        {
            //if (nums[low] < nums[high]) return -1;
            while (low < high)
            {
                //5cout<<low<<" "<<high<<endl;
                int mid = low + (high - low) / 2;
                if (mid < high && nums[mid] > nums[mid + 1]) return mid;	// mid is the pivot
                //else if (mid > low && nums[mid - 1] > nums[mid]) return mid - 1;	// mid-1 is the pivot
                else if (nums[mid] >= nums[low]) low = mid + 1;	//low to mid sorted means no pivot bw low and mid
                else high = mid - 1;	//low to mid not sorted means pivot is there means ignore mid to high part
            }
            return low;
        }
    public:
        int search(vector<int> &nums, int target)
        {
            int n = nums.size();

           	// 2 pass sol
           	// finding pivot
            int pivot = findpivot(nums, 0, n - 1);
            //cout<<pivot<<endl;
            int low = 0, high = pivot;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            low = pivot + 1;
            high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return -1;

           	// https://youtu.be/r3pMQ8-Ad5s
           	// one pass without finding pivot
           	// int low=0, high = n-1;
           	// while (low <= high)
           	// {
           	//     int mid = low + (high - low) / 2;
           	//     if (nums[mid] == target) return mid;
           	//     if (nums[low] <= nums[mid])
           	//     {
           	//         if (target < nums[mid] && target >= nums[low])
           	//         {
           	//             high = mid - 1;
           	//         }
           	//         else
           	//         {
           	//             low = mid + 1;
           	//         }
           	//     }
           	//     else if (nums[mid] <= nums[high])
           	//     {
           	//         if (target > nums[mid] && target <= nums[high])
           	//         {
           	//             low = mid + 1;
           	//         }
           	//         else
           	//         {
           	//             high = mid - 1;;
           	//         }
           	//     }
           	// }
           	// return -1;
        }
};