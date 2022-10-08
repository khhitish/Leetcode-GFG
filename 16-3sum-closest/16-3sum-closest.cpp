class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(),absdiff = INT_MAX, ans;
        int i=0;
        while(i<n)
        {
            int j = i+1, k = n-1;
            while(j<k)
            {
                int curr = nums[i] + nums[j] + nums[k];
                if(curr==target) return curr;
                // cout<<nums[i]<<" "<<j<<" "<<k<<" "<<curr<<endl;
                if(abs(curr-target) < absdiff)
                {
                    ans = curr;
                    absdiff = abs(curr-target);
                }
                if(curr>target)
                {
                    int temp = nums[k];
                    while(k>j && nums[k] == temp)k--;
                }
                else
                {
                    int temp = nums[j];
                    while(j<k && nums[j]==temp)j++;
                }
            }
            int temp = nums[i];
            while(i<n && nums[i]==temp)i++;
        }
        return ans;
    }
};