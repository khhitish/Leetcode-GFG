class Solution
{
    private:
        bool isvowel(char ch)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
            return false;
        }
    public:
       	// can use a queue to store the window, not needed though
        int maxVowels(string s, int k)
        {
            int ans = 0, count = 0, n = s.size();
            for (int i = 0; i < k; i++)
            {
                if (isvowel(s[i]) == true) count++;
            }
            ans = max(ans, count);
            for (int i = k; i < n; i++)
            {
                if (isvowel(s[i]) == true) count++;
                if (isvowel(s[i - k]) == true) count--;
                ans = max(ans, count);
            }
            return ans;
        }
};