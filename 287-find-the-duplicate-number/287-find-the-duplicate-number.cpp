class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // without modifying arry and using constant space 2 approaches
        // binary search the answer time nlogn space 1
        int low=1, high = nums.size()-1, ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int countless=0;
            for(auto&x : nums)
            {
                if(x<=mid) countless++;
            }
            if(countless > mid)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            //cout<<ans<<" ";
        }
        return ans;
    }
};