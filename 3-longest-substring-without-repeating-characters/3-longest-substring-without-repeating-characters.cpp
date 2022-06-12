class Solution
{
   	// https://youtu.be/qtVh-XEpsJo
   	// time = n, space = 256
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> hash(256, -1);
            int left = 0, right = 0, ans = 0;
            while (right < s.size())
            {
                char curr = s[right];
                if (hash[curr] != -1)
                {
                    left = max(hash[curr] + 1, left);
                    hash[curr] = -1;
                }
               	// cout<<left<<endl;
                hash[curr] = right;
                ans = max(ans, right - left + 1);
                right++;
            }
            return ans;
        }
};