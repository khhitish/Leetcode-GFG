class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        long long sum = 0;
        int left = 0,right = 0;
        while(right < n) {
            // cout<<left<<" "<<right<<" "<<sum<<endl;
            sum+=nums[right];
            if(right > 2*k) {
                sum-=nums[left];
                left++;
            }
            if(right - left + 1 == 2*k + 1) {
                ans[right - k] = sum/(2*k + 1);
            }
            right++;
        }
        return ans;
    }
};