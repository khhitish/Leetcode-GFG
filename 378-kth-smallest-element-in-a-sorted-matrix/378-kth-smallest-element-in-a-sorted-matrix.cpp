class Solution
{
    public:
        int kthSmallest(vector<vector < int>> &matrix, int k)
        {
            int n = matrix.size(), m = matrix[0].size();
            int smaller = k-1;
            int low = -1e9, high = 1e9;
            int ans = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int countsmaller = 0, exists = 0;
                for (int i = 0; i < n; i++)
                {
                    int index = lower_bound(matrix[i].begin(), matrix[i].end(), mid) - 
                        matrix[i].begin();
                    if (index< m && matrix[i][index] == mid) exists = 1;
                    countsmaller += (index);
                }
                //cout<<mid<<" "<<countsmaller<<" ";
                if (countsmaller > smaller)
                {
                    high = mid - 1;
                }
                else if (countsmaller < smaller)
                {
                    if (exists == 1) ans = mid;
                    low = mid + 1;
                }
                else
                {
                    if (exists == 1) return mid;
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
            return ans;
        }
};