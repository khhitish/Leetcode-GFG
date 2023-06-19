class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, n = s.size(), ans = 0;
        vector<int> hash(3,0);
        int unique = 0;
        while(right < n) {
            if(hash[s[right] - 'a'] == 0) unique++;
            hash[s[right] - 'a']++;
            ans+=left;
            while(unique >= 3) {
                hash[s[left] - 'a']--;
                if(hash[s[left] - 'a'] == 0) unique--;
                left++;
                ans++;
            }
            right++;
        }
        return ans;
    }
};