class Solution
{
    private:
        bool ispossibleans(int mid, vector<int> &q, int n)
        {
            int reqstores = 0;
            for (int i = 0; i < q.size(); i++)
            {
                int curr = q[i];
                reqstores += curr % mid == 0 ? curr / mid : curr / mid + 1;
                if (reqstores > n) return false;
            }
            return true;
        }
    public:
        int minimizedMaximum(int n, vector<int> &q)
        {
            int low = 0, high = *max_element(q.begin(), q.end());
            int ans = 0;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (mid>0 && ispossibleans(mid, q, n))
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return ans;
        }
};