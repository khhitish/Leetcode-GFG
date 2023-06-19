class Solution {
private:
    int atMostK(vector<int>& nums, int k) {
        int left = 0, right = 0, sum = 0, ans = 0, n = nums.size();
        while(right < n) {
            sum+=nums[right];
            while(sum > k) {
                sum-=nums[left];
                left++;
            }
            ans+=(right - left + 1);
            right++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = atMostK(nums,goal);
        if(goal != 0) ans -= atMostK(nums,goal-1);
        return ans;
    }
};