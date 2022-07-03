class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int left=0, right=0, n=s.size();
        int ans=0;
        while(right<n)
        {
            char curr = s[right];
            if(hash[curr]!=-1)
            {
                left=max(left,hash[curr]+1);
            }
            hash[curr]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};