class Solution
{
    public:
        bool isPalindrome(int x)
        {
            if (x < 0 || (x % 10 == 0 && x != 0)) return false;
            long long curr = x;
            long long rev = 0;
            while (x != 0)
            {
                rev = rev *10 + x % 10;
                x /= 10;
            }
            while (rev > 0)
            {
                if (rev % 10 != curr % 10) return false;
                rev /= 10;
                curr /= 10;
            }
            return true;
        }
};