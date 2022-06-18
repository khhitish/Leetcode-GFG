class Solution
{
   	// https://youtu.be/RrxpTWqj97A
   	// Time: O(n*k*logk) worst case, space: O(k)
    public:
        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            priority_queue<vector < int>, vector< vector< int >>, greater<vector< int>>> pq;
            int mini = INT_MAX, maxi = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                pq.push({ nums[i][0],
                    i,
                    0 });
                maxi = max(maxi, nums[i][0]);
            }
            vector<int> ans(2);
            ans[0] = -1e9;
            ans[1] = 1e9;
            while (true)
            {
                auto v = pq.top();
                pq.pop();
                mini = v[0];
                int i = v[1], j = v[2];
                if ((maxi - mini < ans[1] - ans[0]) || (maxi - mini == ans[1] - ans[0] && mini < ans[0]))
                {
                    ans[0] = mini;
                    ans[1] = maxi;
                }
                if (j + 1 < nums[i].size())
                {
                    pq.push({ nums[i][j + 1],
                        i,
                        j + 1 });
                    maxi = max(maxi, nums[i][j + 1]);
                }
                else break;
            }
            return ans;
        }
};