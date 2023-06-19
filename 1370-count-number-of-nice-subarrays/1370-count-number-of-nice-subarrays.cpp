class Solution {
private:
    int atMostK(vector<int>& nums, int k){
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto&x : nums) {
            x%=2;
        }

        // Sliding window, 2 * O(n) time, O(n) space
        int ans = atMostK(nums, k);
        if(k > 0) ans-= atMostK(nums,k-1);
        return ans;



        // // Hashing O(n) time, O(n) space
        // unordered_map<int, int> mp;
        // int sum = 0;
        // int ans = 0;
        // mp[0] = 1;
        // for(auto&x : nums) {
        //     sum+=x;
        //     ans+=mp[sum-k];
        //     mp[sum]++;
        // }
        // return ans;
    }
};