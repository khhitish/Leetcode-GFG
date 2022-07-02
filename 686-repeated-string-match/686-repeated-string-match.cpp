class Solution
{
    private:
        int rabin_karp(string &s, string &p)
        {
            int n = p.size();	// length of pattern
            int m = s.size();	//length of the searching space
            int mod = 101;
            int phash = 0, shash = 0;
            int power = 1;
            for (int i = 0; i < n - 1; i++)
            {
                power = (power *26) % mod;	//to subtract to slide the window
            }
            for (int i = 0; i < n; i++)
            {
                phash = (phash *26 + (p[i] - 'a' + 1)) % mod;	//forming the initial hash
                shash = (shash *26 + (s[i] - 'a' + 1)) % mod;
            }
            for (int i = 0; i <= m - n; i++)
            {
               	// if we are at i, we have a hash of window starting at i, we are checking and then we are sliding the window to i+1
                if (phash == shash)
                {
                    int j;
                    for (j = i; j < i + n; j++)
                    {
                        if (s[j] != p[j - i]) break;
                    }
                    if (j == i + n) return i;
                }
                if (i < m - n)	// forming the has for the next window 
                {
                    shash = shash - power *(s[i] - 'a' + 1);
                    shash = ((shash *26) % mod + (s[i + n] - 'a' + 1)) % mod;

                    if (shash < 0) shash += mod;
                }
            }
            return -1;
        }

    public:
        int repeatedStringMatch(string a, string b)
        {
            int count = 1;
            if (a == b) return count;
            string ans = a;
            while (ans.size() < b.size())
            {
                ans += a;
                count++;
            }
            if (rabin_karp(ans, b) != -1) return count;
            ans += a;
            count++;
            if (rabin_karp(ans, b) != -1) return count;
            return -1;
        }
};