class Solution
{
   	// time = n, space = 256
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> hash(256, -1);
            int left = 0, right = 0, ans = 0;
            while (right < s.size())
            {
                char curr_val = s[right];
                if (hash[curr_val] != -1)
                {
                    left = max(hash[curr_val] + 1, left);
                    hash[curr_val] = -1;
                }
                hash[curr_val] = right;
                int curr_len = right - left + 1;
                ans = max(ans, curr_len);
                right++;
            }
            return ans;
        }
};