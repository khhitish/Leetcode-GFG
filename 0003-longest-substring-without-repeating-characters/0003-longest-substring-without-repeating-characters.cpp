class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, n = s.size();
        int ans = 0;
        vector<int> hash(256,-1);
        while(right < n) {
            int curr = s[right];
            if(hash[curr] >= left) {
                left = hash[curr] + 1;
            }
            hash[curr] = right;
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};