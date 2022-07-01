class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // without modifying array and using constant space: 2 approaches
        
        // // 1) binary search the answer time nlogn space 1
        // int low=1, high = nums.size()-1, ans=-1;
        // while(low<=high)
        // {
        //     int mid = low + (high-low)/2;
        //     int countless=0;
        //     for(auto&x : nums)
        //     {
        //         if(x<=mid) countless++;
        //     }
        //     if(countless > mid)
        //     {
        //         ans=mid;
        //         high=mid-1;
        //     }
        //     else
        //     {
        //         low=mid+1;
        //     }
        // }
        // return ans;
        
        // 2) Linked list cycle detection 2 //see notes or last approach in the following link
        // https://leetcode.com/problems/find-the-duplicate-number/discuss/1892921/Java-9-Approaches-Count-+-Hash-+-Sort-+-Binary-Search-+-Bit-+-Fast-Slow-Pointers 
        int slow=nums[0], fast=nums[slow];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};