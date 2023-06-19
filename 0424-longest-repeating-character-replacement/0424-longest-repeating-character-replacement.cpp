class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, right=0, ans=0;
        vector<int> freq(26,0);
        char majority = '#';
        int n = s.size();
        while(right < n) {
            freq[s[right] - 'A']++;
            if(majority == '#') majority = s[right];
            else {
                if(freq[s[right] - 'A'] > freq[majority - 'A']) {
                    majority = s[right];
                }
            }
            while(right-left+1 - freq[majority - 'A'] > k) {
                freq[s[left] - 'A']--;
                left++;
                for(int i=0;i<26;i++) {
                    if(freq[i] > freq[majority - 'A']) {
                        majority = 'A' + i;
                    }
                }
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};