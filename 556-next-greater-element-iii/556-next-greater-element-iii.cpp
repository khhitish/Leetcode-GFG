class Solution
{
    public:
        int nextGreaterElement(int n)
        {
            string res = to_string(n);
            //next_permutation(res.begin(), res.end());
            int m = res.size();
            int i = m - 2;
            while (i >= 0 && res[i] >= res[i + 1]) i--;
            if (i < 0) return -1;
            int j = m - 1;
            while (j >= 0 && res[j] <= res[i]) j--;
            swap(res[i], res[j]);
            reverse(res.begin() + i + 1, res.end());
            long long ans = stoll(res);
            if (ans > INT_MAX) return -1;
            return ans;
        }
};