class Solution {
public:
    int minimumSize(vector<int>& nums, int m) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans=0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int count=0;
            for(auto&x : nums)
            {
                count+=x/mid-1;
                if(x%mid!=0) count++;
            }
            if(count>m)
            {
                low=mid+1;
            }
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};