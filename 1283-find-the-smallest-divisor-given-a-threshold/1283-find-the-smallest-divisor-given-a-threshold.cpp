class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(), nums.end());
        int ans=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int sum=0;
            for(auto&x : nums)
            {
                if(x%mid==0) sum+=(x/mid);
                else sum+=(x/mid) + 1;
            }
            if(sum>threshold)
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