class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto&x : nums) {
            x%=2;
        }
        map<long long, int> mp;
        long long sum = 0;
        int ans = 0;
        mp[0] = 1;
        for(auto&x : nums) {
            sum+=x;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};