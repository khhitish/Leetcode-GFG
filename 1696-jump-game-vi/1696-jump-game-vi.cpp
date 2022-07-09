class Solution
{
   	// https://leetcode.com/problems/sliding-window-maximum/
    public:
        int maxResult(vector<int> &nums, int k)
        {
            int n = nums.size();

           	// priority queue to maintain a sliding window maximum of size k
           	// n + nlogn time n space
           	// vector<int> dp(n);
           	// priority_queue<pair<int,int>> pq;
           	// dp[0]=nums[0];
           	// pq.push({dp[0],0});
           	// for(int i=1;i < n;i++)
           	// {
           	//     while(!pq.empty() && pq.top().second < i-k)pq.pop();
           	//     dp[i] = nums[i] + pq.top().first;
           	//     pq.push({dp[i],i});
           	// }
           	// return dp[n-1];

           	// using monotonic deque, decreasing from front to back
            vector<int> dp(n);
            dp[0] = nums[0];
            deque<int> dq;
            dq.push_back(0);
            for (int i = 1; i < n; i++)
            {
                while (!dq.empty() && dq.front() < i - k) dq.pop_front();
                dp[i] = nums[i] + dp[dq.front()];
                while (!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
                dq.push_back(i);
            }
            return dp[n - 1];
        }
};