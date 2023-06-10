class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        long long mod = 1e9+7;
        vector<long long> finalPos(n);
        for(int i=0;i<n;i++) {
            finalPos[i] = nums[i];
            if(s[i] == 'L')finalPos[i]-=d;
            else finalPos[i]+=d;
        }
        sort(finalPos.begin(), finalPos.end());
        long long ans = 0;
        for(int i=1;i<n;i++) {
            long long dist = ((finalPos[i] - finalPos[i-1])%mod + mod)%mod;
            ans = (ans + ((dist*(i)%mod)*(n-i)%mod))%mod;
        }
        return ans;
    }
};